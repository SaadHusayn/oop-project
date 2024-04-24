#include<iostream>
using namespace std;

class C{
    int n,m ;
    public:
    C(int a,int b):n(a), m(b){}

    bool operator==(C &obj){
        return (n == obj.n) && (m == obj.m);
    }
};

int main(){
    C one(1, 2), two(1, 2);

    // cout<<(one == two)<<endl;
    string s;
    // cin>>s;
    std::getline(std::cin, s, static_cast<char>(EOF));
    cout<<"\n"<<s<<endl;
}