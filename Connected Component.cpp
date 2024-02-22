#include<bits/stdc++.h>
using namespace std;
vector<int>G[101];
bool vis[101];

int BFS(int src){

   queue<int>Q;
   Q.push(src);
   vis[src]=1;

   while(!Q.empty()){
      int u=Q.front();
      Q.pop();
      for(int i=0;i<G[u].size();i++){
         int v=G[u][i];
         if(!vis[v]){
           vis[v]=1;
           Q.push(v);
        }
      }

   }

}

int  main(){

  int node,edge;
  scanf("%d%d",&node,&edge);

  for(int i=0;i<edge;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i=0;i<=100;i++){
    vis[i]=0;
  }

  int connected_component=0;

  for(int i=1;i<=node;i++){
    if(!vis[i]){
        connected_component++;
        BFS(i);
    }
  }
  printf("%d\n",connected_component);


return 0;
}
