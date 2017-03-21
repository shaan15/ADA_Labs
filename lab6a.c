#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toggle(int i){
	if(i==0)
		return 1;
	else
		return 0;
}

int min(int x,int y){
	if(x<y){
		return x;
	}
	return y;
}

int main(){
	int n;
	scanf("%d",&n);
	int e1,e2;
	scanf("%d %d",&e1,&e2);

	int arr[2][n+1];
	int mem[2][n+1];
	mem[0][0]=e1;
	mem[1][0]=e2;
	int i;
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
	int j;
	for(j=1;j<=n;j++){
		for(i=0;i<=1;i++){
			/*if(i==0){
				mem[i][j]=e2;

			}
			else if(j==0){
				mem[i][j]=e1;
			}*/
			mem[i][j]=min(mem[i][j-1]+arr[i][j],mem[toggle(i)][j-1]+time[toggle(i)][j]+arr[toggle(i)][j]);
		}
	}
	printf("%d\n", min(mem[0][n],mem[1][n]));
	return 0;
}