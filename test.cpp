#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
class Character{
    protected:
        string name;
        float HP,ATK,DEF;
        static int dem_nhanloai;
    public:
        virtual void Nhap(){
            
            cin>>name;
            cin>>HP>>ATK>>DEF;
            
        }
        void Xuat(){
            cout<<name<<" "<<HP;
        }
        float get_HP(){
            return HP;
        }
        virtual void adjust(){
            return;
        }
        void attack(Character *t){
            if(t->DEF>ATK)return;
            t->HP =t->HP-(ATK - t->DEF);
        }
        bool is_dead(){
            if(HP<=0)return true;
            return false;
        }
        friend class Boss;

      
        

};
int Character::dem_nhanloai =0;
bool cmp(Character a,Character b){
    return a.get_HP()<b.get_HP();
}
class Boss{
    public:
       
        void nhap(){
            Character a;
            a.Nhap();
        }
    

    
       

};
class NhanLoai:public Character{
    private:
        string job_class;
    public:
        void Nhap(){
            Character::Nhap();
           
            cin>>job_class;
            dem_nhanloai++;
         
           
            
        }
        
};
class BanNhan:public Character{
    private:
        string racial;
    public:
        void Nhap(){
            Character::Nhap();
           
            cin>>racial;
           
            
        }
};
class DiHinh:public Character{
    public:


};
class Human:public NhanLoai{
    public:

};
class Elf:public NhanLoai{
    public:
        void adjust(){
            DEF =DEF+0.5*DEF;
        }
};
class Orc:public BanNhan{
    public:
        void adjust(){
            HP+=0.5*HP;
        }

};
class Golbin:public BanNhan{
    public:
        void adjust(){
            ATK +=0.1*ATK;
        }
};
class Vampire:public DiHinh{
    public:
        void adjust(){
            HP +=0.1*HP*dem_nhanloai;
        }

};
class Devil:public DiHinh{
    protected:
        static int dem_devil;
    public:
        void Nhap(){
            DiHinh::Nhap();
            dem_devil++;

        }
        void adjust(){
            ATK +=0.1*ATK*dem_devil;
            DEF +=DEF*0.1*dem_devil;
        }
};
int Devil::dem_devil =0;
class Guild{
    private:
        int soluong;
        Character *t[100];
       
       
     
       

        int loai;
    public:
        
        void Nhap(){
            cout<<"nhap so luong";
            cin>>soluong;
            int i=0;
            for(i=0;i<soluong;i++){
                cout<<"nhap loai:";
                cin>>loai;
                if(loai==1){
                    t[i] =new Human();
                }else if(loai==2){
                    t[i] =new Elf();
                }else if(loai==3){
                    t[i] =new Orc();
                }else if(loai==4){
                    t[i] =new Golbin();
                }else if(loai==5){
                    t[i] =new Vampire();
                }else if(loai==6){
                    t[i]=new Devil();
                }
                t[i]->Nhap();
            }
           
            cout<<"nhap boss";
            
            for(int i=0;i<soluong;i++){
                t[i]->adjust();
            }

        }
        void who_win(){
            int dem=0;
            for(int i=0;i<soluong;i++){
                if(!t[i]->is_dead()){
                    t[i]->attack(t[soluong]);
                    if(t[soluong]->is_dead()==true){
                        dem=1;
                        break;
                    }
                }
            }
            if(dem==0){
                t[soluong]->Xuat();
            }else{
                sort(t[0],t[soluong],cmp);
                for(int i=0;i<soluong;i++){
                    t[soluong]->attack(t[i]);
                    if(t[i]->is_dead()==true){
                        continue;
                    }else{
                        break;
                    }
                }
                for(int i=0;i<soluong;i++){
                    if(t[i]->is_dead()==false){
                        t[i]->Xuat();
                        cout<<endl;
                    }
                }
            }
        }
       
};
int main(){
    Guild *t;
   
    t->Nhap();
    
    t->who_win();
    
}