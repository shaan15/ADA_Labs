#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10001

struct snode{
	int data;
	int dist;
	int final;
	char colour;
	int integer;
  struct snode * next;
	struct snode * p;
};
typedef struct snode node;
node *temp,*temp2,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];


struct stack{
	int arr[MAX_SIZE];
	int top;
};
typedef struct stack STACK;
STACK s;
int flag;

void create(int value){
  	temp=(node *)malloc(sizeof(node));
  	temp->next=NULL;
  	temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	temp->colour='g';
	temp->integer = 0;
}

void insert_end(node ** head,node ** tail,int x){
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



void pop(STACK *stk){
	if(stk->top==-1){
		return;
	}
	else{
		printf("%d ",stk->arr[stk->top]);
		stk->top--;
	}
}

void push(STACK *stk,int num){
	if(stk->top==MAX_SIZE-1){
		return;
	}
	else{
		stk->top++;
		stk->arr[stk->top]=num;
	}
}


void dfs_visit(node * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		//push(&s,*t);
		u->colour = 'g';
		node * temp4 = u->next;
		
		while(temp4 != NULL && (u->colour=='b')){
			temp2 = head[temp4->data];
			if(temp2->colour=='w'){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			else if(temp2->colour=='g'){
				//printf("FAIL\n");
				//return 1;
				flag = 1;
				return;
			}
			temp4 =temp4->next;
		}
		u->colour='b';
		(*t)=(*t)+1;
		u->final=(*t);
	/*	if(u->integer == 0){
			u->integer = 1;
		push(&s,u->data);
	}*/

		
		//printf("%d pushed into stack\n",u->data);
}

void dfs(int n){
	int i;
	for(i=1 ; i<(n+1) ; i++){
		head[i]->colour='w';
		head[i]->p=NULL;
	}
	int t=0;
	for(i=1 ; i<(n+1); i++){
		if(head[i]->colour=='w'){
			dfs_visit(head[i],&t);
			/*if(dfs_visit(head[i],&t) == 1){
				return 1;
			}*/
		}
	}
	
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		flag = 0;
		s.top = -1;
  		int i,n;
  		scanf("%d",&n);
		for(i=1;i<(n+1);i++){
			create(i);
			head[i]=temp;
			tail[i]=NULL;
		}
		for(i=1;i<(n+1);i++){
			int m;
			scanf("%d",&m);
			/*int arr[m];
			int j;
			for(j=0;j<m;j++){
				scanf("%d",&arr[j]);
				insert_end(&(head[i]->next),&(tail[i]),arr[j]);
			}*/
			while(m--){
				int x;
				scanf("%d",&x);
				insert_end(&(head[i]->next),&(tail[i]),x);
			}
		}
		/*int x,y;
 		scanf("%d %d",&x,&y);
  		while(x!=-1 && y!=-1){
    		insert_end(&(head[x]->next),&(tail[x]),y);
    		scanf("%d %d",&x,&y);
  		}*/

	}
	return 0;
}