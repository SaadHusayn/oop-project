#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream myfile("file.txt", ios::in | ios::out | ios::app);
    myfile<<"appending...";
}