#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z){
	if (x < y && x <z){
		return x;
	}
    if(y < x && y < z){
    	return y;
    }
    else{
    	return z;
    }
}

int ed(char * str1, char * str2, int m, int n){
	int arr[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0){
				arr[i][j]=j;
			}
			else if(j==0){
				arr[i][j]==i;
			}
			else if(str1[i-1]==str2[j-1]){
				arr[i][j]=arr[i-1][j-1];
			}
			else{
				arr[i][j]=min(arr[i][j-1],arr[i-1][j],arr[i-1][j-1])+1;
			}
		}
	}
	return arr[m][n];
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	char str1[m], str2[n];
	scanf("%s",str1);
	scanf("%s",str2);

	int cost = ed(str1,str2,m,n);
	printf("%d\n",cost);
}