#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int dem[100][100];
void solve(int arr[][100],int n,int m){
    pair<int,int>s,e;
    cin>>s.first>>s.second>>e.first>>e.second;
    queue<pair<int,int>>value;
    value.push({s.first,s.second});
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    while(1){
        pair<int,int>top =value.front();
        value.pop();
        int a =top.first;
        int b =top.second;
        for(int i=0;i<4;i++){
            int x =a+dx[i];
            int y =b+dy[i];
            if(arr[x][y]&&x>=0&&x<n&&y>=0&&y<m){
                if(x==e.first&&y ==e.second){
                    cout<<dem[a][b]+1;
                    return;
                }
                value.push({x,y});
                dem[x][y] =dem[a][b]+1;

            }
        }

    }


}
int main(){
    memset(dem,0,sizeof(dem));
    int arr[100][100];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    solve(arr,n,m);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<dem[i][j];
    //     }
    // }
}