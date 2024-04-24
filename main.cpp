#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class UserInfo{
    protected:
    char full_name[40], description[120], password[20],  security_question[20], username[20];

    public:
    UserInfo(){}

    void getData(){
        system("cls");

        cout<<"\nEnter Full Name: "<<endl;
        cin.getline(full_name, sizeof(full_name));

        cout<<"Enter Username: "<<endl;
        cin.getline(username, sizeof(username));

        cout<<"Enter Password: "<<endl;
        cin.getline(password, sizeof(password));

        cout<<"Enter Description/Bio: "<<endl;
        cin.getline(description, sizeof(description));

        cout<<"Security Question: What is your favourite athelete?"<<endl;
        cin.getline(security_question, sizeof(security_question));

    }

    void storeInFile(){
        fstream f;
        f.open("usersinfo.dat",ios::binary | ios::app);

        if(f){
            f.write(reinterpret_cast<char*>(this), sizeof(*this));
            f.close();
            cout<<"\nInformation stored successfully"<<endl;
            system("pause");
        }
        else cout<<"\nError Opening File"<<endl;
    }

    void readFromFile(){
        fstream f;
        f.open("usersinfo.dat",ios::binary | ios::in);

        if(f){
            f.read(reinterpret_cast<char*>(this), sizeof(*this));
            while(f){
                displayUserInfo();
                f.read(reinterpret_cast<char*>(this), sizeof(*this));
            }
            f.close();
            system("pause");
        }
        else cout<<"\nError Opening File"<<endl;
    }

    void displayUserInfo(){
        cout<<"\nName: "<<full_name<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
        cout<<"Description/Bio: "<<description<<endl;
        cout<<"Favourite Athele: "<<security_question<<endl;

        system("pause");
    }
};

class LoginPage {
public:
    void display() {
        system("cls");
        // cout << "\nUsername: ";
        // cin >> username;
        // cout << "Password: ";
        // cin >> password;

        UserInfo userinfo;
        
        userinfo.readFromFile();

        // userinfo.displayUserInfo();
    }

private:
    string username;
    string password;
};

class SignupPage {
public:
    void display() {
        UserInfo userinfo;

        userinfo.getData();

        userinfo.storeInFile();

    }
};

class HelpPage {
public:
    void display() {
        system("cls");
        cout << "This is help Page" << endl;
        cout << "you can further reach us on whatsapp for help" << endl;
        system("pause");
    }
};

class AboutPage {
public:
    void display() {
        system("cls");
        cout << "This is about Page" << endl;
        cout << "This software is created by Farhan, Sabih and Saad" << endl;
        system("pause");
    }
};

class SocializeApp {
public:
    void displayMenu() {
        system("cls");
        cout << "Welcome To Socialize" << endl << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Help" << endl;
        cout << "4. About" << endl;
        cout << "5. Exit" << endl;
    }

    void run() {
        while(true){
            int choice;
            do {
                displayMenu();
                cout << "\nEnter your choice: ";
                choice = getch() - '0';
                switch (choice) {
                    case 1:
                        loginPage.display();
                        break;
                    case 2:
                        signupPage.display();
                        break;
                    case 3:
                        helpPage.display();
                        break;
                    case 4:
                        aboutPage.display();
                        break;
                    case 5:
                        Sleep(1000);
                        exit(0);
                }
            } while (choice < 1 || choice > 5);
        }
    }

private:
    LoginPage loginPage;
    SignupPage signupPage;
    HelpPage helpPage;
    AboutPage aboutPage;
};

int main() {
    SocializeApp app;
    app.run();
    return 0;
}