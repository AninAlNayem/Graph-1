#include<bits/stdc++.h>
using namespace std;
const int mx=10001;

vector<int>G[mx];
bool vis[mx];
int dist[mx];

void BFS(int src){

  queue<int>Q;
  Q.push(src);
  vis[src]=1;
  dist[src]=0;

  while(!Q.empty()){

    int u=Q.front();
    Q.pop();
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){
            vis[v]=1;
            dist[v]=dist[u]+1;
            Q.push(v);
        }
    }

  }

}

void Set(){
    for(int i=0;i<mx;i++){
      vis[i]=0;
      dist[i]=-1;
    }
}

int main(){

  int node,edge,weight;
  scanf("%d%d%d",&node,&edge,&weight);
  for(int i=0;i<edge;i++){
    int u,v;scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  Set();
  BFS(1);
  for(int i=1;i<=node;i++){
    if(dist[i]>0){
        dist[i]*=weight;
    }
    printf("%d ",dist[i]);
  }

return 0;
}
