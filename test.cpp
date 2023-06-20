#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *pre;
    Node *pos;
};
typedef Node* node;
node create(int data){
    node t =new Node();
    t->data =data;
    t->pre=t->pos=NULL;
    return t;
}
void assign(node&doubly){
    doubly->pos=doubly->pre=NULL;
}
void add_node_previous(node&doubly,int data){
    node temp =create(data);
    temp->pos =doubly;
    if(doubly!=nullptr){
        doubly->pre =temp;
    }
    doubly =temp;

}
void add_node_post(node&doubly,int data){
    node temp =create(data);
   
    if(doubly==nullptr){
       
        // temp->pre =doubly;
        doubly =temp;
    }else{
        node dummy =doubly;
        while(dummy->pos!=nullptr){
            dummy =dummy->pos;
        }
        dummy->pos =temp;
        temp->pre =dummy;
        
    }
   
    
}
int amount_node(node doubly){
    int dem=0;
    while(doubly!=NULL){
        dem++;
        doubly =doubly->pos;
    }
    return dem;
}
void add_middle(node&doubly,int index,int data){
    node temp =create(data);
    if(doubly==NULL)return;
    if(index==1){
        add_node_previous(doubly,data);
    }else if(index>=amount_node(doubly)+1){
        add_node_post(doubly,data);
    }else{
        node dummy_node =doubly;
        int i=1;
        while(i<index-1){
            dummy_node =dummy_node->pos;
            i++;
            
        }
        temp->pos =dummy_node->pos;
        dummy_node->pos->pre =temp;
        temp->pre =dummy_node;
        dummy_node->pos =temp;
        

    }
}

void print(node doubly){
    while(doubly!=NULL){
        cout<<doubly->data;
        doubly =doubly->pos;
    }
}
node reverse(node doubly){
    node prev=nullptr;
    node current =doubly;
    while(current!=nullptr){
        prev =current->pre;
        current->pre =current->pos;
        current->pos =prev;
        prev =current;
        current =current->pre;
    }
    return prev;
    


   
    
 

}
void size_reverse(node &doubly,int a,int b){
    node head =doubly;
    node tail =doubly;
    int i=1;
    int j=1;
    while(i<a-1){
        head =head->pos;
        i++;
    }
    node t =head->pos;

    t->pre=nullptr;
    while(j<b){
        tail=tail->pos;
        j++;
    }
    node sau =tail->pos;
    node truoc =tail;
    int x=1;
    // while(x<2){
    //     truoc =truoc->pos;
    //     x++;
    // }
    tail->pos=nullptr;

    t =reverse(t);
    head->pos =t;
    t->pre=head;
   
    while(x<amount_node(tail)){
        truoc =truoc->pos;
        x++;
    }
    truoc->pos =sau;
    

   
   
    print(doubly);

}
int main(){
    Node*t=NULL;
    
  
    add_node_post(t,1);
    add_node_post(t,2);
    add_node_post(t,6);
    add_node_post(t,7);
    add_node_post(t,9);
    add_node_post(t,10);
    add_node_post(t,11);
    add_node_post(t,12);
    
    size_reverse(t,2,6);
    // print(a);
    
}