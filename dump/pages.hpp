#ifndef PAGES_H
#define PAGES_H

#include<iostream>
using namespace std;
#define USERNAME_SIZE 20
#define PASSWORD_SIZE 20
#define FULL_NAME_SIZE 40
#define DESCRIPTION_SIZE 120
#define SECURITY_QUESTION_SIZE 20

class ViewPostPage {
public:
    void display() {
        system("cls");
        cout << "This is This is View Post Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class FriendRequestPage {
public:
    void display() {
        system("cls");
        cout << "This is This is Friend Request Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class AddFriendsPage {
public:
    void display() {
        system("cls");
        cout << "This is This is Add Friends Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class YourInformationPage {
public:
    void display() {
        system("cls");
        cout << "This is This is Your Information Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};



class UserInfo{
    protected:
    char full_name[FULL_NAME_SIZE], description[DESCRIPTION_SIZE], password[PASSWORD_SIZE],  security_question[SECURITY_QUESTION_SIZE], username[USERNAME_SIZE];

    public:
    UserInfo(){}

    //getters and setters
    void set_full_name(char *_full_name){strcpy(full_name, _full_name);}
    char get_full_name(char *_full_name){strcpy(_full_name, full_name);}

    void set_description(char *_description){strcpy(description, _description);}
    char get_description(char *_description){strcpy(_description, description);}

    void set_password(char *_password){strcpy(password, _password);}
    char get_password(char *_password){strcpy(_password, password);}

    void set_security_question(char *_security_question){strcpy(security_question, _security_question);}
    char get_security_question(char *_security_question){strcpy(_security_question, security_question);}

    void set_username(char *_username){strcpy(username, _username);}
    char get_username(char *_username){strcpy(_username, username);}

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

    void displayAllUserInfo(){
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

    bool isValidInfo(char _username[], char _password[]){
        fstream f;
        f.open("usersinfo.dat", ios::in | ios::binary);

        if(f){
            f.read(reinterpret_cast<char*>(this), sizeof(*this));
            while(f){
                if((!strcmp(username, _username)) && (!strcmp(password, _password))){
                    f.close();
                    return true;
                }
                f.read(reinterpret_cast<char*>(this), sizeof(*this));
            }
            f.close();
            return false;
        }
        else  cerr<<"\nError Opening File"<<endl;
    }
};


class AccountDashboardPage{
    
    private:
    FriendRequestPage friendrequestsPage;
    AddFriendsPage addfriendsPage;
    ViewPostPage viewpostsPage;
    YourInformationPage yourinformationPage;
    UserInfo userinfo;


    public:
    AccountDashboardPage(){}
    AccountDashboardPage(UserInfo uinfo): userinfo(uinfo){}

    void displayMenu(){
        
        system("cls");
        cout << "Welcome To Socialize" << endl;
        cout << "Account DashBoard For "<<  endl << endl;
        cout << "1. View Posts" << endl;
        cout << "2. View Friend Requests" << endl;
        cout << "3. Add Friends" << endl;
        cout << "4. Your Information" << endl;
        cout << "5. Log Out"<<endl;
        cout << "6. Exit"<<endl;
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
                        viewpostsPage.display();
                        break;
                    }
                    case 2:
                    {
                        friendrequestsPage.display();
                        break;
                    }
                    case 3:
                    {
                        addfriendsPage.display();
                        break;
                    }
                    case 4:
                    {
                        yourinformationPage.display();
                        break;
                    }
                    case 5:
                    {
                        return;
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

class LoginPage {
private:
    char username[USERNAME_SIZE], password[PASSWORD_SIZE];
    AccountDashboardPage accountdashboardpage;
public:
    void display() {
        system("cls");
        cout << "\nUsername: ";
        cin.getline(username, sizeof(username));
        cout << "Password: ";
        cin.getline(password, sizeof(password));

        UserInfo userinfo;
        
        if(userinfo.isValidInfo(username, password)){
            cout<<"\nLogin Successful"<<endl;
            accountdashboardpage.run();
        }
        else{
            cout<<"Login Not Successful"<<endl;
            // showLoginNotSuccessfullPage();
        }

        system("pause");

        // userinfo.readFromFile();

        // userinfo.displayUserInfo();
    }


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

#endif