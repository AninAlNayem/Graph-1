#include<bits/stdc++.h>
using namespace std;

vector<int>G[51];


int main(){

   int nodes,edges;
   cin>>nodes>>edges;
   while(edges--){
     int u,v;
     cin>>u>>v;
     G[u].push_back(v);
     G[v].push_back(u);
   }

   for(int i=1;i<=nodes;i++){
      printf("%d -> ",i);
      for(int j=0;j<G[i].size();j++){
        printf("%d ",G[i][j]);
      }
      printf("\n");
   }

return 0;
}
