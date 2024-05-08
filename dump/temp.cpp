#include<iostream>
#include<string.h>
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
    // char s[100];
    // cin>>s;
    getline(cin, s, static_cast<char>(-1));

    const char *str = s.c_str();
    cout<<"\n"<<str<<endl;
    cout<<sizeof(str)<<endl;
}