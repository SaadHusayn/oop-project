#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void displayMenu(){
    system("cls");
    cout<<"Welcome To Socialize"<<endl<<endl;

    cout<<"1. Login"<<endl;
    cout<<"2. Signup"<<endl;
    cout<<"3. Help"<<endl;
    cout<<"4. About"<<endl;
    cout<<"5. Exit"<<endl;
}

void loginPage(){
    system("cls");

    // cout<<"This is login Page"<<endl;

    string username, password;

    cout<<"\nUsername: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    // cin>>password;



}

void signupPage(){
    system("cls");

    cout<<"This is signup Page"<<endl;
    system("pause");
}

void helpPage(){
    system("cls");

    cout<<"This is help Page"<<endl;
    cout<<"you can further reach us on whatsapp for help"<<endl;
    system("pause");
    return;
}

void aboutPage(){
    system("cls");

    cout<<"This is about Page"<<endl;
    cout<<"This software is created by Farhan, Sabih and Saad"<<endl;
    system("pause");
    return;
}

void startingPage(){
    system("cls");

    int choice;


    do{
        displayMenu();

        cout<<"\nEnter your choice: ";
        // choice = getch() - '0';
        choice = 


        switch(choice){
            case 1:
            loginPage();
            break;

            case 2:
            signupPage();
            break;

            case 3:
            helpPage();
            break;

            case 4:
            aboutPage();
            break;

            case 5:
            exit(0);
            
        }

    }while(choice < 1 || choice > 4);
}

int main(){
    while(1) startingPage();
}