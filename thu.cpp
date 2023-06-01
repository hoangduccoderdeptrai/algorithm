#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Solution{
    private:
        static const int capacity =10;
        // mảng capacity row 
        // moi row có nhieu cac key vulue khác nhau nhưng cùng cung hash value(indexx)
        list<pair<int,string>>hashtable[capacity];
    public:
        bool isEmpty();
        int hashFunction(int key);
        void removeIteam(int key);
        void insertItem(int key,string value);
        void PrintTable();

};
bool Solution::isEmpty(){

    for(int i=0;i<capacity;i++){
        if(hashtable[i].size()>0){
            return false;
        }
    }
    return true;
}
// find hash value as a hash index
int Solution::hashFunction(int key){
    return key%capacity;
}
void Solution::insertItem(int key,string value){
    int hashIndex =hashFunction(key);
    auto&  cell =hashtable[hashIndex];
    for(auto& x:cell){
        if(x.first==key){
            x.second =value;
            return;
            
        }
    }
    cell.emplace_back(make_pair(key,value));
}
void Solution::removeIteam(int key){
    int hashindex =hashFunction(key);
    auto & cell =hashtable[hashindex];
    // auto start =begin(cell);
    auto start =cell.begin();
    for(;start!=end(cell);start++){
        if(start->first==key){
            cell.remove(*start);
            return;
        }
    }
    cout<<"not found ";
}
void Solution::PrintTable(){
    for(int i=0;i<capacity;i++){
        if(hashtable[i].size()==0)continue;
        for(auto x:hashtable[i]){
            cout<<x.first<<" "<<x.second<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Solution t;
    t.insertItem(1,"le hoang duc");
    t.insertItem(2,"tran van son");
    t.insertItem(3,"nguyen huu tho");
    t.insertItem(11,"doi thanh duc dep trai");
    t.removeIteam(1);
    t.PrintTable();
}