#include<bits/stdc++.h>
using namespace std;
char grid[101][101];
bool vis[101][101];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int grid_BFS(int r,int c,int n,int m){

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           vis[i][j]=0;
        }
     }

     queue<int>Qx,Qy;

     Qx.push(r);
     Qy.push(c);
     vis[r][c]=1;
     int cnt=0;

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

int main(){

    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
        }
    }
    int gold=grid_BFS(x,y,n,m);
    printf("%d\n",gold);

return 0;
}
