#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VER 1001
#define MAX_EDGES 1000001
#define lt(x) 2 * x + 1
#define rt(x) 2 * x + 2
#define parent(x) (x - 1) / 2



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
node * head[MAX_VER];
node * tail[MAX_VER];

struct sedge
{
	int start;
	int end;
	int wt;
};

typedef struct sedge edge;
edge * edge_arr[MAX_EDGES][2];
int count = 0, count_A = 0, count_B = 0, count_C = 0;
edge * A[MAX_EDGES];
edge * B[MAX_EDGES];
edge * C[MAX_EDGES];

struct heapnode {
    int d;
};
typedef struct heapnode heapnode;

struct minHeap {
    int size ;
    heapnode *elem ;
};
typedef struct minHeap minHeap;

node * create_node(int val){
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next=NULL;
  	newnode->data=val;
	newnode->dist=-1;
	newnode->colour='w';
	return newnode;
}




edge * create_edge(int x,int y,int w){
	edge * tp=(edge *)malloc(sizeof(edge));
	tp->start=x;
	tp->end=y;
	tp->w=w;
	return tp;
}


void insert_end(node ** head,node ** tail,int x){
  if(*head==NULL){
    temp = create_node(x);
    *head=temp;
    *tail=temp;
  }
  else{
    temp = create_node(x);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}

minHeap initMinHeap() {
    minHeap hp;
    hp.size = 0;
    return hp ;
}

void insertNode(minHeap *hp, int data){
    if(hp->size) {
        hp->elem = realloc(hp->elem, (size + 1) * sizeof(node)) ;
    } else {
        hp->elem = malloc(sizeof(node)) ;
    }
    node nd ;
    nd.d = data ;

    int i = (hp->size)++ ;
    while(i && nd.data < hp->elem[parent(i)].data) {
        hp->elem[i] = hp->elem[parent(i)] ;
        i = parent(i) ;
    }
    hp->elem[i] = nd ;
}

void swap(node *x, node *y) {
    node x_temp = *x ;
    *x = *y ;
    *y = x_temp ;
}

void heapify(minHeap *hp, int i) {
    int smallest = (lt(i) < hp->size && hp->elem[lt(i)].data < hp->elem[i].data) ? lt(i) : i ;
    if(rt(i) < hp->size && hp->elem[rt(i)].data < hp->elem[largest].data) {
        smallest = rt(i) ;
    }
    if(smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }
}

void deleteNode(minHeap *hp) {
    if(hp->size) {
        printf("Deleting node %d\n\n", hp->elem[0].data) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        heapify(hp, 0) ;
    } else {
        printf("\nMin Heap is empty!\n") ;
        free(hp->elem) ;
    }
}

void djisktra(node *s, node *t){
	s->dist=0;
	node * temp4 = s->next;
	minHeap hp = initMinHeap();



}

int main(){
		//flag = 0;
		//s.top = -1;
  		int j,N,E;
  		scanf("%d %d",&N, &E);

		for(j=1;j<(N+1);j++){
			create(j);
			head[j]=temp;
			tail[j]=NULL;
		}
		while(E--){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			insert_end(&(head[a]->next),&tail[a],b);
			edge_arr[count][0] = create_edge(a,b,w);
			
			insert_end(&(head[b]->next),&tail[b],a);
			edge_arr[count][1]=create_edge(b,a,w);
			
			count++;

		}  		

		int sa,sb,sc;
		scanf("%d",&sa);
		while(sa--){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			A[count_A]->start = a;
			A[count_A]->end = b;
			A[count_A]->wt = w;
			count_A++;



		}
		

}