#include<iostream>
#include<fstream>
#include<string.h>
#include "temp.hpp"
using namespace std;

class A{
    public:
    int b=3;
    int j;
    char arr[32];

    A(int m):j(m){}
    void get(){
        cout<<this->b<<endl;
        cout<<sizeof(this)<<endl;
        cout<<sizeof(*this)<<endl;
    }
    

    friend bool operator== (A a1, A a2){
        return 3;
    }
};

char * foo(char  c[]){return c;}

int main(){
    // char name[40];
    // // cin>>name;
    // cin.getline(name, sizeof(name));
    // cout<<name;
    // cout<<4;

    // A fff;
    // fff.get();

    // cout<<3;
    // system("pause");
    // cout<<34;

    // A fff(30), ggg(40);
    // cout<<fff.j<<" "<<ggg.j<<endl;
    // fff = ggg;
    // cout<<fff.j<<" "<<ggg.j<<endl;
    // cout<<(fff == ggg);

    // int a[] = {1,2,  3, 4,5 ,5555,5 , 323};
    // for(auto i:a) cout<<i<<" ";

    // fstream f;
    // f.open("usersinfo.dat", ios::in);
    // if(f){
    //     f.read(reinterpret_cast<char*>(&fff), sizeof(fff));
    //     cout<<"\n"<<f.tellg()<<endl;
    // }


    // char abc[30] = "Babar Azam";
    // cout<<abc<< " " <<sizeof(abc)<<endl;
    // strcpy(abc, "Amir");
    // cout<<abc<< " " <<sizeof(abc)<<endl;

    
}