#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 301

struct treenode{
	int data;
	int dist;
	int end;
	char colour;
  struct treenode * next;
	struct treenode * p;
};
typedef struct treenode node;
node *temp,*temp1,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];

struct dist_queue{
	node * arr[MAX_SIZE];
	int head;
	int tail;
};
typedef struct dist_queue queue;

void enqueue(queue **q,node ** s){
			(*q)->arr[(*q)->tail]=(*s);
			if((*q)->tail==MAX_SIZE-1){
				(*q)->tail=0;
			}
			else{
			 (*q)->tail++;
			}
	}

node * dequeue(queue **q){
	if((*q)->head == (*q)->tail){
		return NULL;
	}
	else{
		temp=(*q)->arr[(*q)->head];
		if((*q)->head==MAX_SIZE-1){
			(*q)->head=0;
		}
		else{
		 (*q)->head++;
		}
		return temp;
	}
}

void create(int val){
  temp=(node *)malloc(sizeof(node));
  temp->next=NULL;
  temp->data=val;
	temp->p=NULL;
	temp->dist=-1;
	temp->end=0;
	temp->colour = 'w';

}

void insert_end(node ** head,node ** tail,int x){
  if((*head)==NULL){
    create(x);
    (*head)=temp;
    (*tail)=temp;
  }
  else{
    create(x);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}

void bfs(queue * q,node * s,int n, int K, int sum){
	int i;
	for(i=1;i<n+1;i++){
		head[i]->colour = 'w';
		
	}

	s->colour = 'g';
	s->dist=0;
	q->head=0;
	q->tail=0;
	enqueue(&q,&s);
	while(q->head != q->tail){
		temp = dequeue(&q);
		temp1 = head[temp->data]->next;
		while(temp1!=NULL){
			temp3 =	head[temp1->data];
			if(temp3->colour == 'w'){
				temp3->colour = 'g';
				temp3->dist=temp->dist+1;
				// temp3->p=temp;
				enqueue(&q,&temp3);
			}
			temp1=temp1->next;
		}
		temp->colour = 'b';
		if(temp->dist > 1 && temp->dist <= K){
			sum++;
		}
	}
	printf("%d\n",sum);
}

int main(){
		queue q;
		// node *root=NULL;
/*		head = NULL;
		tail=NULL;*/
		int N,F,K;
		scanf("%d %d %d",&N,&F,&K);
		int j;
		for(j=1;j<(N+1);j++){
			create(j);
			head[j]=temp;
			tail[j]=NULL;
		}
		while(F--){
			int a,b;
			scanf("%d %d",&a,&b);
			insert_end(&(head[a]->next),&tail[a],b);
			insert_end(&(head[b]->next),&tail[b],a);
		}
		//QUEUE *q;
		q.head=0;
		q.tail=0;
		int m;
		for(m=1;m<(N+1);m++){
			int sum = 0;
			node * s=head[m];
			bfs(&q,s,N,K,sum);
		}
		
		// int i;
		// int min=0;
		// for(i=1;i<(n+1);i++){
		// 	if((head[i])->dist < min){
		// 		min = (head[i])->dist;
		// 	}
		// }
		//printf("%d\n",head[n]->dist);
	
	return 0;
}
