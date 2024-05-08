#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;

#define USERNAME_SIZE 20
#define PASSWORD_SIZE 20
#define FULL_NAME_SIZE 40
#define DESCRIPTION_SIZE 120
#define DATE_OF_BIRTH_SIZE 30
#define GENDER_SIZE 10
#define SECURITY_QUESTION_SIZE 20

class UserInfo{
    protected:
    char full_name[FULL_NAME_SIZE], description[DESCRIPTION_SIZE], password[PASSWORD_SIZE],  security_question[SECURITY_QUESTION_SIZE], username[USERNAME_SIZE], date_of_birth[DATE_OF_BIRTH_SIZE], gender[GENDER_SIZE];

    public:
    UserInfo(){}

    //getters and setters
    void set_full_name(char *_full_name){strcpy(full_name, _full_name);}
    void get_full_name(char *_full_name){strcpy(_full_name, full_name);}

    void set_description(char *_description){strcpy(description, _description);}
    void get_description(char *_description){strcpy(_description, description);}

    void set_password(char *_password){strcpy(password, _password);}
    void get_password(char *_password){strcpy(_password, password);}

    void set_security_question(char *_security_question){strcpy(security_question, _security_question);}
    void get_security_question(char *_security_question){strcpy(_security_question, security_question);}

    void set_username(char *_username){strcpy(username, _username);}
    void get_username(char *_username){strcpy(_username, username);}

    void set_date_of_birth(char *_date_of_birth){strcpy(date_of_birth, _date_of_birth);}
    void get_date_of_birth(char *_date_of_birth){strcpy(_date_of_birth, date_of_birth);}

    void set_gender(char *_gender){strcpy(gender, _gender);}
    void get_gender(char *_gender){strcpy(_gender, gender);}

    void getData(){
        system("cls");

        cout<<"\nEnter Full Name: "<<endl;
        cin.getline(full_name, FULL_NAME_SIZE);

        cout<<"Enter Username: "<<endl;
        cin.getline(username, USERNAME_SIZE);

        cout<<"Enter Password: "<<endl;
        cin.getline(password, PASSWORD_SIZE);

        cout<<"Enter Date Of Birth: "<<endl;
        cin.getline(date_of_birth, DATE_OF_BIRTH_SIZE);

        cout<<"Enter Gender: "<<endl;
        cin.getline(gender, GENDER_SIZE);

        cout<<"Enter Description/Bio: "<<endl;
        cin.getline(description, DESCRIPTION_SIZE);

        cout<<"Security Question: What is your favourite athelete?"<<endl;
        cin.getline(security_question, SECURITY_QUESTION_SIZE);

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
        cout<<"Date Of Birth: "<<date_of_birth<<endl;
        cout<<"Gender: "<<gender<<endl;
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


class ViewPostPage {
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is View Post Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class CreatePostPage {
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Create Post Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class EditPostPage {
    
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Edit Post Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class DeletePostPage {
    
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Delete Post Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};


class AddCommentPage {
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Add Comments Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};

class  AddLikePage{
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Add Like Page of The User" << endl;
        cout << "we are still working on it" << endl;
        system("pause");
    }
};


class YourInformationPage {
private:
UserInfo userinfo;
public:
    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
    }
    void display() {
        system("cls");
        cout << "This is This is Your Information Page of The User" << endl;
        userinfo.displayUserInfo();
        system("pause");
    }
};

class AccountDashboardPage{
    
    private:
    ViewPostPage viewpostPage;
    CreatePostPage createpostPage;
    EditPostPage editpostPage;
    DeletePostPage deletepostPage;
    AddCommentPage addcommentPage;
    AddLikePage addlikePage;
    YourInformationPage yourinformationPage;
    UserInfo userinfo;


    public:
    AccountDashboardPage(){}
    AccountDashboardPage(UserInfo uinfo): userinfo(uinfo){}

    void setUserInfo(UserInfo uinfo){
        userinfo = uinfo;
        viewpostPage.setUserInfo(userinfo);
        createpostPage.setUserInfo(userinfo);
        editpostPage.setUserInfo(userinfo);
        deletepostPage.setUserInfo(userinfo);
        addcommentPage.setUserInfo(userinfo);
        addlikePage.setUserInfo(userinfo);
        yourinformationPage.setUserInfo(userinfo);
    }

    void displayMenu(){
        
        system("cls");
        cout << "Welcome To Socialize" << endl;
        cout << "Account DashBoard For "<<  endl << endl;
        cout << "1. View All Posts" << endl;
        cout << "2. Create Post" << endl;
        cout << "3. Edit Post" << endl;
        cout << "4. Delete Post" << endl;
        cout << "5. Add Comment To Post" << endl;
        cout << "6. Add Like To Post"<<endl;
        cout << "7. View Your Information"<<endl;
        cout << "8. Logout Account"<<endl;
        cout << "9. Exit"<<endl;
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
                        viewpostPage.display();
                        break;
                    }
                    case 2:
                    {
                        createpostPage.display();
                        break;
                    }
                    case 3:
                    {
                        editpostPage.display();
                        break;
                    }
                    case 4:
                    {
                        deletepostPage.display();
                        break;
                    }
                    case 5:
                    {
                        addcommentPage.display();
                        break;
                    }
                    case 6:
                    {
                        addlikePage.display();
                        break;
                    }
                    case 7:
                    {
                        yourinformationPage.display();
                        break;
                    }
                    case 8:
                    {
                        return;
                    }
                    case 9:
                    {
                        Sleep(1000);
                        exit(0);
                    }
                }
            } while (choice < 1 || choice > 9);
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
            accountdashboardpage.setUserInfo(userinfo);
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

#endif