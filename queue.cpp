#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;

};
typedef Node* tree;
tree make_node(int x){
    tree node =new Node();
    node->data =x;
    node->left =node->right=nullptr;
    return node;

}

void depth_travesal(tree root){
    queue<pair<tree,int>>que;
    map<int,int>mp;
    
    que.push(make_pair(root,0));
   
    while(que.size()>0){
        pair<tree,int>date =que.front();
        int x =date.second;
       if(mp.find(x)==mp.end())
            mp[x] =date.first->data;
        que.pop();
        
        
        if(date.first->right!=nullptr)que.push(make_pair(date.first->right,x+1));
        if(date.first->left!=nullptr){
            que.push(make_pair(date.first->left,x+1));
        }
    }
    
   
}
void priorder(tree root){
    if(root==NULL)return;
    
    priorder(root->left);
    priorder(root->right);
}
bool get1(Node* root, Node* p,vector<Node*>&vt){
    if(root==nullptr)return false;
    vt.push_back(root);
    if(root->data ==p->data)return true;
    if(get1(root->left,p,vt)||get1(root->right,p,vt)){
        return true;
    }
    vt.pop_back();
    return false;

}
Node* lowestCommonAncestor(Node* root, Node* p,Node* q) {
    vector<Node*>vt1;
    vector<Node*>vt2;
    get1(root,p,vt1);
    get1(root,q,vt2);
    if(root==nullptr)return nullptr;
    reverse(vt1.begin(),vt1.end());
    reverse(vt2.begin(),vt2.end());
    for(int i=0;i<vt1.size();i++){
        for(int j=0;j<vt2.size();j++){
            if(vt1[i]->data==vt2[j]->data){
                return vt1[i];
            }
        }
    }
    
}
void cc(vector<vector<int>>adj[]){
    for(auto it:adj[1]){
        int a =it[0];
        int b =it[1];
        cout<<a<<" "<<b;

    }
    
}
vector<int>kkk(int v,vector<vector<int>>adjacent[],int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>stored(v);
    for(int i=0;i<v;i++){
        stored[i] =10000;
    }
    stored[source]=0;
    pq.push({0,source});
  
    while (!pq.empty())
    {
        int distance =pq.top().first;
        int node =pq.top().second;
        pq.pop();
        for(auto it:adjacent[node]){
            int adjacent_edge =it[1];
            int adjacent_node =it[0];
            if(distance+adjacent_edge<stored[adjacent_node]){
                stored[adjacent_node] =distance+adjacent_edge;
                pq.push({stored[adjacent_node],adjacent_node});
            }
        }
    }
    return stored;


}
void hehe(int v,)
int main(){
    // Node* root =nullptr;
    // root =make_node(1);
    // root->left =make_node(2);
    // root->right =make_node(3);
    // root->left->left=make_node(4);
    // root->left->right =make_node(5);
    // root->right->left =NULL;
    // root->right->right =make_node(7);
    // root->left->right->left =make_node(6);
    // root->left->right->right =NULL;
    vector<vector<int>>clm{
        {0,7,2,0,0,0},
        {7,0,0,2,1,0},
        {2,0,0,0,3,0},
        {0,2,0,0,9,3},
        {0,1,3,9,0,8},
        {0,0,0,3,8,0}};
   
    // vector<vector<int>>adj[]={{{1,4},{2,4}},
    //             {{0,4},{2,2}},
    //             {{0,4},{1,2},{3,3},{4,1},{5,6}},
    //             {{2,3},{5,2}},
    //             {{2,1},{5,3}},
    //             {{2,6},{3,2},{4,3}}};
    // adj ={{{1,9}},{{0,9}}};
    vector<vector<int>>adj[100];
     
    for(int i=0;i<clm.size();i++){
        for(int j=0;j<clm[i].size();j++){
            if(clm[i][j]!=0)
                adj[i].push_back({j,clm[i][j]});
                
        }
      
    }
    int v =clm.size();
 
    vector<int>vt =kkk(v,adj,0);
   
    for(int i=0;i<vt.size();i++){
        cout<<"minimun from 0 to "<<i<<"la:"<<vt[i]<<endl;
    }
   
   
    
   
   
}