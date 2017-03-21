#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000000
long long int INFINITY = 1000000000000;

struct node_placeholder{
  int data;
  float weight;
  struct node_placeholder * next;
};
typedef struct node_placeholder NODE_PLACEHOLDER;

struct node{
  int data;
  float key;
  // int weights[MAX_SIZE];
  struct node_placeholder * next;
  struct node * p;
};
typedef struct node NODE;

NODE_PLACEHOLDER *temp;
NODE *temp2,*temp3;
NODE * head[MAX_SIZE];
NODE_PLACEHOLDER * tail[MAX_SIZE];

void create_placeholder(int value,int weight){
  temp=(NODE_PLACEHOLDER *)malloc(sizeof(NODE_PLACEHOLDER));
  temp->weight=weight;
  temp->next=NULL;
  temp->data=value;
}

void create(int value){
  temp2=(NODE *)malloc(sizeof(NODE));
  temp2->next=NULL;
  temp2->data=value;
  temp2->p=NULL;
  temp2->key=0.0;
}

void insert_end(NODE_PLACEHOLDER ** head,NODE_PLACEHOLDER ** tail,int x,int weight){
  if(*head==NULL){
    create_placeholder(x,weight);
    *head=temp;
    *tail=temp;
  }
  else{
    create_placeholder(x,weight);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}


int bellman(int start,int v){
  int i,j,k;
  for(i=1;i<=v;i++){
      head[i]->key=0.0;
      head[i]->p=NULL;
    }
  head[start]->key=1.0;
  
  for(i=1;i<=v;i++){
    if(i!=start){
      for(j=1;j<=v;j++){

        

        temp=head[j]->next;
        // printf("%d\n", temp->data);
        // temp=head[u->data]->next;
      temp3=head[j];
      while(temp!=NULL){
        printf("%d\n", temp->data);
        
        // printf("%s\n", );
        temp2=head[temp->data];
        if( temp3->key < temp2->key * temp->weight ){
        // printf("%d\n", temp2->data);
          
          temp3->p=temp2;

          temp3->key=temp->weight * temp2->key;
        }
      temp=temp->next;
      }
    }
    }
  }
//   for(j=1;j<=v;j++){
//       if(start==3){
//           printf("%f\n", head[j]->key);
//         }

// }

  for(j=1;j<=v;j++){
        temp=head[j]->next;
        // temp=head[u->data]->next;
      temp3=head[j];
      while(temp!=NULL){
        temp2=head[temp->data];
        printf("%f\n", temp->weight);
        if( temp3->key < temp2->key * temp->weight ){
          printf("YES\n");
          return 1;
          }
      temp=temp->next;
      }
    }
    // printf("NO\n");
    return 0;
}

int main(){
  int i,j,n,v,e;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&v);
    e=v*v;
    // EDGE array[e];
    // EDGE final[e];
    int count=0;
    for(i=1 ; i<=v ; i++){
      create(i);
      head[i]=temp2;
      tail[i]=NULL;
    }
    int matrix[v+1][v+1];
    float adj[v+1][v+1];
    for(i=1 ; i<=v ; i++){
      for(j=1 ; j<=v ; j++){
        float weight;
        scanf("%f",&weight);
      // make_edge(a,b,c);
        
        adj[i][j]=weight;
        //insert_end(&(head[i]->next),&(tail[i]),j,weight);
      // insert_end(&(head[b]->next),&(tail[b]),a,c);
      }
    }
    

    int flag=0;
    for(i=1;i<=v;i++){
      
      if(bellman(i,v)==1){
        printf("YES\n");
        flag=1;
        break;
      }
    }
    if(flag==0)printf("NO\n");

    
  
  }
  return 0;
}