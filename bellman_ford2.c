#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
#include <math.h>
 
/*int a,b,u,v,n,i,j,ne=1;
 
int visited[10]={0},min,mincost=0,cost[10][10];*/

int head[MAX_SIZE];

int Bellman_Ford(int n,double G[n][n] ,int V, int E, int edge[n][n])
{
    int i,u,v,k,distance[20],parent[20],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000 , parent[i] = -1 ;
        //printf("Enter source: ");
        //scanf("%d",&S);

      for(S=1;S<V;S++){
        distance[S-1]=0;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
              break;
        }
      }


        distance[S-1]=0;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
              
        }
        

        return flag;
}


int main()
{
    
     int t;
  scanf("%d",&t);
  while(t--){
  //int V,edge[n+1][n+1],i,j,k=0;
  int V,i,j,k=0;
  int n;
  scanf("%d",&n);
  double G[n][n];
  int edge[n][n];
  //int i,j;
  for(i=1;i<n+1;i++){
    for(j=1;j<n+1;j++){
      scanf("%lf",&G[i][j]);
      G[i][j]=-log(G[i][j]);
      if(G[i][j]!=0)
        edge[k][0]=i,edge[k++][1]=j;
    }
  }
  if(Bellman_Ford(n,G,V,k,edge)==0){
      printf("YES\n");
  }
  else{
    printf("NO\n");
  }

  return 0;
  }
}
 