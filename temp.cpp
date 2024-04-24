#include<iostream>
#include<fstream>
using namespace std;

class A{
    int b=3;
    int j;
    char arr[32];

    public:
    void get(){
        cout<<this->b<<endl;
        cout<<sizeof(this)<<endl;
        cout<<sizeof(*this)<<endl;
    }
    

    friend bool operator== (A a1, A a2){
        return 3;
    }
};

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

    A fff, ggg;
    cout<<(fff == ggg);

    int a[] = {1,2,  3, 4,5 ,5555,5 , 323};
    for(auto i:a) cout<<i<<" ";

    fstream f;
    f.open("usersinfo.dat", ios::in);
    if(f){
        cout<<"\n"<<f.tellg()<<endl;
    }
}