#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // ofstream MyFile("file.txt");
    // MyFile<<"Contents of the file";

    // MyFile.close();

    ifstream myfile("1.txt");
    string str;
    while(getline(myfile, str)){
        cout<<str<<endl;
    }
}