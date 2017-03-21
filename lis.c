#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lis(int * arr, int n){
	int *L;
	L = (int*)malloc(n*sizeof(int));
	int i,j;
	int max = 0;
	for(i=0;i<n;i++){
		L[i]=1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if((arr[i]>arr[j]) && (L[i]<L[j]+1)){
				L[i]=L[j]+1;
			}
		}
	}
	for(i=0;i<n;i++){
		if(max<L[i]){
			max=L[i];
		}
	}
	free(L);
	return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}