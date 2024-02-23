#include<bits/stdc++.h>
using namespace std;

const int inf=1e8;

const int mx=1e4+1;
vector< pair<int,int> >G[mx];

void BFS_01(int src,int node){

   vector<int>dis(node+1,inf);
   dis[src]=0;

   deque<int>deq;
   deq.push_front(src);

   while(!deq.empty()){

      int u=deq.front();
      deq.pop_front();

      for(int i=0;i<G[u].size();i++){
        int v=G[u][i].first;
        int w=G[u][i].second;

        if(dis[u]+w<dis[v]){
            dis[v]=dis[u]+w;
            if(w==1){
                deq.push_back(v);
            }
            else{
                deq.push_front(v);
            }
        }
      }

   }

   for(int i=1;i<=node;i++){
     if(dis[i]==inf){
        dis[i]=-1;
     }
     printf("%d ",dis[i]);
   }printf("\n");

}


int main(){

   int node,edge;
   scanf("%d%d",&node,&edge);
   while(edge--){
     int u,v,w;
     scanf("%d%d%d",&u,&v,&w);
     G[u].push_back(make_pair(v,w));
     G[v].push_back(make_pair(u,w));
   }
   BFS_01(1,node);

return 0;
}
