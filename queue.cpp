#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
map<int,int>mp;
int solve(string a,int k){
    if(k==0)return 1;
    int check =a.length()-k;
    if(a[check]=='0')return 0;
    if(mp.find(mp[k])==mp.end()){
        if(k>=2 &&stoi(a.substr(check,2))<=26){
            mp[k] =( solve(a,k-1)+solve(a,k-2));
            return mp[k];
        }
        mp[k] = solve(a,k-1);
        return mp[k];
    }else{
        return mp[k];
    }

}
int results(string a){
    int leng =a.length();
    return solve(a,leng);
}
int main(){
    cout<<results("0134");
    
}