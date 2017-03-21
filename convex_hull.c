#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct point{
	int x;
	int y;
};
typedef struct point point;

point* create_point(int x,int y){
	point *bottom = (point*)malloc(sizeof(point));
	bottom->x=x;
	bottom->y=y;
	return bottom;
}

/*void merge(point *arr[],int p,int q,int r){
	int i,j,k,s;
	point *L[q-p+2],*R[r-q+1];
	for(i=p,j=0;i<=q,j<=(q-p);i++,j++){
			L[j]->x=arr[i]->x;
			L[j]->y=arr[i]->y;
			//L2[j]=arr2[i];
			//printf("copied to L\n");

	}
	for(s=q+1,k=0;s<=r,k<(r-q+1);s++,k++){
			R[k]->x=arr[s]->x;
			R[k]->y=arr[s]->y;
			//R2[k]=arr2[s];
			//printf("copied to R\n");
	}
	L[q-p+1]->x=1000000;
	L[q-p+1]->y=1000000;
	R[r-q]->x=1000000;
	R[r-q]->y=1000000;
	//printf("sentinel declared\n");

	int m=0,n=0,a;
	//int y_index=0;
	for(a=p;a<=r;a++){
		if((L[m]->x)<=(R[n]->x)){
			arr[a]->x=L[m]->x;
			arr[a]->y=L[m]->y;
			//arr2[y_index]=L2[m];
			m++;
			//y_index++;
			//printf("L dominates\n");
		}
		else{
			arr[a]->x=R[n]->x;
			arr[a]->y=R[n]->y;
			//arr2[y_index]=R2[n];
			n++;
			//y_index++;
			//printf("R dominates\n");
		}
	}
	//printf("merging done\n");

}

void merge_sort(point *arr[],int start,int end){
	int mid;
	if(start<end){
	mid=(start+end)/2;
	//printf("mid found\n");


	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);
	//printf("Now sorted!");
	}
}*/

point* merge_hulls(int Lsize, int Rsize,point *L[], point *R[]){

}

/*point* find_hull(int n, point *s[n], int start, int end){
	if(n>3){
		int h=n/2;
		int m=n-h;
		point **L,**R;
		*L=find_hull(h,s,start,h);
		*R=find_hull(m,s,h+1,end);
		return merge_hulls(h-start+1,end-h,L,R);
	}
	else{
		return s[1]; //hull of s by exhaustive search
	}

}*/

int main(){
	int n;
	scanf("%d",&n);
	//int arr_x[n],arr_y[n];
	int i;
	point * arr_pts[n];
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		//arr_x[i]=x;
		//arr_y[i]=y;
		arr_pts[i]=create_point(x,y);

	}

	sort(arr_pts,0,n-1);
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d %d\n",arr_pts[i]->x,arr_pts[i]->y);
	}
	return 0;

}