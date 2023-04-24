#include<iostream>
using namespace std;
struct sv{
	string  name;
	string mssv;
	float gpa;
	void nhap(){
		
		cout<<"nhap ten:";
		
		getline(cin,name);
		if(name=="")return;
		cout<<"nhap mssv:";
	
		getline(cin,mssv);
		cout<<"nhap gpa:";
		cin>>gpa;
		cin.ignore();
		
	}
	void hienthi(){
		cout<<name<<" "<<mssv<<" "<<gpa<<endl;
	}
};
struct Node{
	sv a;
	Node* next;

};
struct DS_NODE{
	Node* head;
	Node* tail;
};
void create_empty(DS_NODE &l){
	l.head =nullptr;
	l.tail=nullptr;
}
int size(DS_NODE  l){
	int cnt =0;
	while(l.head!=nullptr){
		cnt++;
		l.head =l.head->next;
	}
	return cnt;
}
Node* make_sv(){
	sv t;
	t.nhap();
	Node* p=new Node();
	p->a =t;
	p->next =NULL;
	return p;		

}
void add_node_head(DS_NODE &l){
	Node* p =make_sv();
	if(l.head ==nullptr){
		l.head =p;
		l.tail =l.head;

	}else{
		p->next =l.head;
		l.head =p;
	}
}
bool search(DS_NODE l){
	int si =size(l);
	string ten;
	cout<<"nhap ten de tim kiem:";
	getline(cin,ten);
	for(int i=0;i<si;i++){
		if(ten.find(l.head->a.name)!=string::npos)return true;
		l.head =l.head->next;
	}
	return false;

}
void remove(DS_NODE &l){
	string ms;
	cout<<"nhap mssv de xoa sinh vien:";
	cin>>ms;
	Node* p=l.head;
	Node* pre =NULL;
	int kt=0;
	while(p->next!=nullptr){
		pre =p;
		p =p->next;
	
		if(stoi(p->a.mssv) ==stoi(ms)){
			kt=1;
			break;
		}		
	}
	if(kt==0){
		if(stoi(p->a.mssv)!=stoi(ms))return;
	}
	if(pre ==nullptr){
		l.head =nullptr;
		l.tail =l.head;
		return;
	}
	if(p->next ==nullptr){
		pre->next =nullptr;
		l.tail =pre;
		return;
	}
	pre->next =p->next;
}
void listed(DS_NODE l){
	while(l.head!=nullptr){
		if(l.head->a.gpa>=5){
			l.head->a.hienthi();
		}
		l.head =l.head->next;
	}

}
void xep_loai(DS_NODE l){
	while(l.head!=nullptr){
		if(l.head->a.gpa<=3.6){
			l.head->a.hienthi();
			cout<<" Loai trung binh"<<endl;
		}
		else if(l.head->a.gpa>=5.0 && l.head->a.gpa<6.5){
			l.head->a.hienthi();
			cout<<" Loai trung binh "<<endl;
		}
		else if(l.head->a.gpa<7.0){
			l.head->a.hienthi();
			cout<<"Loai trung binh kha"<<endl;

		}else if(l.head->a.gpa<8){
			l.head->a.hienthi();
			cout<<" Loai kha"<<endl;
		}else{
			l.head->a.hienthi();
			cout<<" Loai gioi"<<endl;
		}
		l.head =l.head->next;
	}
}
void sort(DS_NODE &l){
	Node * p;
	Node *j;
	for(p =l.head;p->next!=NULL;p =p->next){
		
		for(j =p->next;j!=NULL;j =j->next){
			if(p->a.gpa>j->a.gpa){
				swap(p->a,j->a);
			}
		}
		
	}
}
void insert_sort(DS_NODE &l){
	Node* p=make_sv();
	DS_NODE c=l;
	if(l.head ==NULL){
		l.head =p;
		l.tail =l.head;
		return ;
	}
	while(c.head->next!=NULL){
		if(p->a.gpa>=c.head->a.gpa&& p->a.gpa<=c.head->next->a.gpa){
			p->next =c.head->next;
			c.head->next =p;
			return;
			
		}else if(p->a.gpa<c.head->a.gpa){
			p->next =l.head;
			l.head =p;
			return;

		}
		
		c.head=c.head->next;
	}
	
	// fix loi cho nay

	if(p->a.gpa<c.head->a.gpa){
		p->next =l.head;
		l.head =p;
		return;
	}
	if(c.head->next==nullptr){
		c.tail->next =p;
		c.tail=p;
		return;
	}
	


	
}
int main(){
	DS_NODE l;
	create_empty(l);
	while(true){
		add_node_head(l);
		if(l.head->a.name==""){
			l.head =l.head->next;
			break;
		}
	}
	// sort(l);
	insert_sort(l);
	
	int leng =size(l);
	for(int i=0;i<leng;i++){
		l.head->a.hienthi();
		l.head =l.head->next;

	}
	
	
}