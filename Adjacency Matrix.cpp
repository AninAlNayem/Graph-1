#include<bits/stdc++.h>
using namespace std;

bool adjMatrix[51][51];

void Set(){
  for(int i=0;i<51;i++){
    for(int j=0;j<51;j++){
        adjMatrix[i][j]=0;
    }
  }
}

int main(){

   int nodes,edges;
   Set();
   cin>>nodes>>edges;
   while(edges--){
     int u,v;
     cin>>u>>v;
     adjMatrix[u][v]=1;
     adjMatrix[v][u]=1;
   }
   for(int i=1;i<=nodes;i++){
     for(int j=1;j<=nodes;j++){
        cout<<adjMatrix[i][j];
     }
     cout<<"\n";
   }

return 0;
}
