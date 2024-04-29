#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#include<string.h>
#include"pages.hpp"
using namespace std;

#define USERNAME_SIZE 20
#define PASSWORD_SIZE 20
#define FULL_NAME_SIZE 40
#define DESCRIPTION_SIZE 120
#define SECURITY_QUESTION_SIZE 20




class SocializeApp {
private:
    LoginPage loginPage;
    SignupPage signupPage;
    HelpPage helpPage;
    AboutPage aboutPage;
    UserInfo uinfo;

public:
    void displayMenu() {
        system("cls");
        cout << "Welcome To Socialize" << endl << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Help" << endl;
        cout << "4. About" << endl;
        cout << "5. Display All Users"<<endl;
        cout << "6. Exit" << endl;
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
                    {
                        loginPage.display();
                        break;
                    }
                    case 2:
                    {
                        signupPage.display();
                        break;
                    }
                    case 3:
                    {
                        helpPage.display();
                        break;
                    }
                    case 4:
                    {
                        aboutPage.display();
                        break;
                    }
                    case 5:
                    {
                        uinfo.displayAllUserInfo();
                        break;
                    }
                    case 6:
                    {
                        Sleep(1000);
                        exit(0);
                    }
                }
            } while (choice < 1 || choice > 6);
        }
    }

};

int main() {
    SocializeApp app;
    app.run();
    return 0;
}