#include<iostream>
#include<vector>
using namespace std;
class solution{
    private:
        void back_track(int i,int j,vector<vector<int>>&vt,vector<int>&ans,int name,int n,int m,vector<vector<int>>&zero){
            if(i==n-1&&j==m-1){
                ans.push_back(name);
                return;
            }
            if(i+1<n &&!zero[i+1][j]){
                if(i+1==n-1&&j==m-1){
                    zero[i][j]=1;
                    back_track(i+1,j,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }else if(vt[i+1][j]==1){
                    zero[i][j]=1;
                    back_track(i+1,j,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }
            }
            if(j-1>=0&&!zero[i][j-1]){
                if(i==n-1&&j-1==m-1){
                    zero[i][j]=1;
                    back_track(i,j-1,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }else if(vt[i][j-1]==1){
                    zero[i][j]=1;
                    back_track(i,j-1,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }
            }
            if(j+1<m&&!zero[i][j+1]){
                if(i==n-1&&j+1==m-1){
                    zero[i][j]=1;
                    back_track(i,j+1,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }else if(vt[i][j+1]==1){
                    zero[i][j]=1;
                    back_track(i,j+1,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }
            }
            if(i-1>=0&&!zero[i-1][j]){
                if(i-1==n-1&&j==m-1){
                    zero[i][j]=1;
                    back_track(i-1,j,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }else if(vt[i-1][j]==1){
                    zero[i][j]=1;
                    back_track(i-1,j,vt,ans,name+1,n,m,zero);
                    zero[i][j]=0;
                }

            }


        } 
    public:
        vector<int>find(vector<vector<int>>vt,vector<int>ans,int n,int m,int name){
            vector<vector<int>>zero(n,vector<int>(m,0));
            back_track(0,0,vt,ans,name,n,m,zero);
            return ans;

        }


};
int main(){
    vector<vector<int>>vt;
    vector<int>ans;
    
    int n,m;

    int arr[100][100];
    cin>>n>>m;
    
    for(int i=0;i<9;i++){
        vector<int>v1;
        for(int j=0;j<10;j++){
            cin>>arr[i][j];
            v1.push_back(arr[i][j]);

        }
        vt.push_back(v1);
    }
    solution t;
    vector<int>result=t.find(vt,ans,n,m,0);
    if(result.size()==0){
        cout<<-1;
    }else{
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
    }
// 4
// 5
// 1 0 1 1 1 1 0 1 1 1
// 1 0 1 0 1 1 1 0 1 1
// 1 1 1 0 1 1 0 1 0 1
// 0 0 0 0 1 0 0 0 0 1
// 1 1 1 0 1 1 1 0 1 0
// 1 0 1 1 1 1 0 1 0 0
// 1 0 0 0 0 0 0 0 0 1
// 1 0 1 1 1 1 0 1 1 1
// 1 1 0 0 0 0 1 0 0 1


}