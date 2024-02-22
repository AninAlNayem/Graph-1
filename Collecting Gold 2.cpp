#include<bits/stdc++.h>
using namespace std;
char grid[501][501];
int componentNode[501][501];
int gold[501];
bool vis[501][501];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int grid_BFS(int r,int c,int n,int m,int indicator){

     queue<int>Qx,Qy;

     Qx.push(r);
     Qy.push(c);
     vis[r][c]=1;
     int cnt=0;
     if(grid[r][c]=='g'){
        cnt++;
     }
     componentNode[r][c]=indicator;

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
                componentNode[newx][newy]=indicator;

                if(grid[newx][newy]=='#'){
                    continue;
                }
                if(grid[newx][newy]=='.' || grid[newx][newy]=='g'){
                    if(grid[newx][newy]=='g'){
                        cnt++;
                    }
                    Qx.push(newx),Qy.push(newy);
                }

            }

        }

     }

return cnt;
}

void Set(int n,int m){
  for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           vis[i][j]=0;
           componentNode[i][j]=0;
        }
  }
  for(int i=0;i<=500;i++){
    gold[i]=0;
  }
}

int main(){

    int t;scanf("%d",&t);
    while(t--){
       int n,m,q;
       scanf("%d%d%d%d",&n,&m,&q);
       for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>grid[i][j];
            }
       }
       Set(n,m);
       int indicator=0,ans=0;
       while(q--){
           int x,y;scanf("%d%d",&x,&y);
           if(vis[x][y]==1){
             ans=gold[componentNode[x][y]];
           }
           else{
             int res=grid_BFS(x,y,n,m,++indicator);
             gold[indicator]=res;
             ans=res;
           }

           printf("%d\n",ans);
       }
    }

return 0;
}
