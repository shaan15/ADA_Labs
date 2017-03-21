#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	int dist;
	int final;
	char color[6];
	int wt;
  struct node * next;
	struct node * p;
};
struct edge
{
	int start;
	int end;
	int wt;
	
};
typedef struct node NODE;
NODE *temp,*temp2,*temp3;
NODE * head[MAX_SIZE];
NODE * tail[MAX_SIZE];

void create(int value){
  temp=(NODE *)malloc(sizeof(NODE));
  temp->next=NULL;
  temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	strcpy(temp->color,"DULL");
}

void insert_end(NODE ** head,NODE ** tail,int x){
  if(*head==NULL){
    create(x);
    *head=temp;
    *tail=temp;
  }
  else{
    create(x);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}

int min(int x, int y, int z){
	if (x < y){
		return x;
	}
	return y;
}


int checkstate(int node, int n, int wt[n]){
	int total=0;
	for(i=1;i<=n;i++){

	}
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n+1][n+1];
		int i,j;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				arr[i][j]=0;
			}
		}
		
		while(n>=1){
			int a,b;
			scanf("%d %d",&a,&b);
			arr[a][b]=1;
			n--;
		}
		int wt[n];
		for(i=0;i<n;i++){
			scanf("%d",&wt[i]);
		}
		int total=0;
		for(i=0;i<)
		for(i=0;i<n;i++){
			printf("%d\n",checkstate(i,n,wt));
		}



		/*for(i=0;i<MAX_SIZE;i++){
			
			temp=head[i]->next;
			while(temp!=NULL){
				printf("%d ",temp->data);
				temp=temp->next;
		}
		printf("\n");
	}*/

	}

	
}