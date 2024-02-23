#include<bits/stdc++.h>
using namespace std;

vector<int>G[101];
char grid[101][101];
bool vis[101][101];
int dist[101][101];

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int BFS(int r,int c,int n,int m){

   queue<int>Qx,Qy;
   Qx.push(r);
   Qy.push(c);
   vis[r][c]=1;
   dist[r][c]=1;

   while(!Qx.empty()){

     int x=Qx.front();
     int y=Qy.front();

     Qx.pop(),Qy.pop();

     for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx<1 || newy<1 || newx>n || newy>m){
           continue;
        }
        if(!vis[newx][newy]){
            vis[newx][newy]=1;
            if(grid[newx][newy]=='#'){
                continue;
            }
            else{
               dist[newx][newy]=1+dist[x][y];
               Qx.push(newx);
               Qy.push(newy);
            }
        }
     }

   }
   if(dist[n][m]==0){
     dist[n][m]=-1;
   }

return dist[n][m];
}

void Set(){

  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
        vis[i][j]=dist[i][j]=0;
    }
  }

}

int main(){

   int n,m;scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
        cin>>grid[i][j];
     }
   }

   Set();
   int minDistance=BFS(1,1,n,m);
   printf("%d\n",minDistance);

return 0;
}
