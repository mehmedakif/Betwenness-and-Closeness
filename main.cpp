#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 9999
#define max 20
int dijkstra(int G[max][max],int n,int startnode,int between_node);

int toplam_shortest_path = 0;
int main()
{
    int G[max][max] =
    {
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0},
    };

   int visit = 0;
   for(int i=0;i<10;i++){
        for(int j=10;j<20;j++){
                if(i==j) continue;
            visit = dijkstra(G,j,i,0)+visit;
        }
   }
   //aradalik();
   return 0;
}
int dijkstra(int G[max][max],int n,int startnode,int between_node)
{
     float centerness;
    int how_many_times_between=0;
   int cost[max][max],distance[max],pred[max];
   int count,mindistance,nextnode,i,j;
   float visited[max];
   float path_length = 0.0f;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]= 0;
   visited[startnode]= 1;
   count=1;
   while(count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
         path_length=path_length+1;

      }
      count++;

   }
   centerness = 1/path_length;

    float global_toplam=0;
   for(i=0;i<n;i++)

   if(i!=startnode)
    {
        toplam_shortest_path = toplam_shortest_path + 1;
      j=i;
      do
      {
        if(between_node==j){ visited[between_node]= visited[between_node]+1;};

         j=pred[j];
      }while(j!=startnode);
   }
   cout<<" # "<<i<<endl;
   cout<<"Dugumden gecen path sayisi = "<<visited[between_node]<< " Toplam shortest path sayisi = " << i << endl;
   float i_i = i;

   float bolum = ((visited[between_node]) / i_i);
   cout<<"Bolum degeri = "<<bolum<<endl;
   global_toplam = global_toplam+bolum;

    cout<<"Node "<<i+1<<"'in Betweennes degeri = "<<global_toplam<<endl;
    cout<<"Centerness degeri = "<<centerness<<endl;
    cout<<" -------- "<<endl;
   return visited[between_node];
}


