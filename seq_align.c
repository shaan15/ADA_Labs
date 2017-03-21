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

int ed(char * str1, char * str2, int m, int n, int insert, int delete, int update){
	int arr[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0){
				arr[i][j]=j+delete;
			}
			else if(j==0){
				arr[i][j]==i+insert;
			}
			else if(str1[i-1]==str2[j-1]){
				arr[i][j]=arr[i-1][j-1]+update;
			}
			else{
				arr[i][j]=min(arr[i][j-1]+insert,arr[i-1][j]+delete,arr[i-1][j-1]+update);
			}
		}
	}
	return arr[m][n];
}

int main(){
	int m,n;
	int insert,delete,update;
	scanf("%d %d",&m,&n);
	scanf("%d %d %d",&insert,&delete,&update);
	char str1[m], str2[n];
	scanf("%s",str1);
	scanf("%s",str2);

	int cost = ed(str1,str2,m,n,insert,delete,update);
	printf("%d\n",cost);
}