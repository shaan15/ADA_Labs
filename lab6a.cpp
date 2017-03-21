#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int min(int a,int b){
	if(a<=b)
		return a;
		
	return b;
}

int comp(int i){
	if(i==1)
		return 0;
	else
		return 1;
}

int main(){
	int i,j,n;
	scanf("%d",&n);
	int e1,e2;
	scanf("%d %d",&e1,&e2);

	int arr[2][n+1];
	int mem[2][n+1];
	mem[0][0]=e1;
	mem[1][0]=e2;

	for(i=1;i<=n;i++){
		scanf("%d",&arr[0][i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&arr[1][i]);
	}

	/*for(i=0;i<=1;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<=1;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&time[i][j]);
		}
	}
*/
	int time[2][n+1];
	for(i=1;i<=n;i++){
		scanf("%d",&time[0][i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&time[1][i]);
	}

	for(j=1;j<=n;j++){
		for(i=0;i<=1;i++){
			/*if(i==0){
				mem[i][j]=e2;

			}
			else if(j==0){
				mem[i][j]=e1;
			}*/
			mem[i][j]=min(mem[i][j-1]+arr[i][j],mem[comp(i)][j-1]+time[comp(i)][j]+arr[comp(i)][j]);
		}
	}
	printf("%d\n", min(mem[0][n],mem[1][n]));
	return 0;
}