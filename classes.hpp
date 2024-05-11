#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include<ios>
#include<cstdio>
#include<limits>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

#define USERNAME_SIZE 20
#define PASSWORD_SIZE 20
#define FULL_NAME_SIZE 40
#define DESCRIPTION_SIZE 120
#define DATE_OF_BIRTH_SIZE 30
#define GENDER_SIZE 10
#define SECURITY_QUESTION_SIZE 20
#define CONTENT_SIZE 1000
#define MAX_COMMENTS 50
#define COMMENT_SIZE 50
#define TITLE_SIZE 50

class UserInfo
{
protected:
    char full_name[FULL_NAME_SIZE], description[DESCRIPTION_SIZE], password[PASSWORD_SIZE], security_question[SECURITY_QUESTION_SIZE], username[USERNAME_SIZE], date_of_birth[DATE_OF_BIRTH_SIZE], gender[GENDER_SIZE];

public:
    UserInfo() {}

    // getters and setters
    void set_full_name(const char *_full_name)
    {
        strncpy(full_name, _full_name, FULL_NAME_SIZE - 1);
        full_name[FULL_NAME_SIZE - 1] = '\0';
    }
    const char *get_full_name() { return full_name; }

    void set_description(const char *_description)
    {
        strncpy(description, _description, DESCRIPTION_SIZE - 1);
        description[DESCRIPTION_SIZE - 1] = '\0';
    }
    const char *get_description() { return description; }

    void set_password(const char *_password)
    {
        strncpy(password, _password, PASSWORD_SIZE - 1);
        password[PASSWORD_SIZE - 1] = '\0';
    }
    const char *get_password() { return password; }

    void set_security_question(const char *_security_question)
    {
        strncpy(security_question, _security_question, SECURITY_QUESTION_SIZE - 1);
        security_question[SECURITY_QUESTION_SIZE - 1] = '\0';
    }
    const char *get_security_question() { return security_question; }

    void set_username(const char *_username)
    {
        strncpy(username, _username, USERNAME_SIZE - 1);
        username[USERNAME_SIZE - 1] = '\0';
    }
    const char *get_username() { return username; }

    void set_date_of_birth(const char *_date_of_birth)
    {
        strncpy(date_of_birth, _date_of_birth, DATE_OF_BIRTH_SIZE - 1);
        date_of_birth[DATE_OF_BIRTH_SIZE - 1] = '\0';
    }
    const char *get_date_of_birth() { return date_of_birth; }

    void set_gender(const char *_gender)
    {
        strncpy(gender, _gender, GENDER_SIZE - 1);
        gender[GENDER_SIZE - 1] = '\0';
    }
    const char *get_gender() { return gender; }

    void getData()
    {
        system("cls");

        cout << "\nEnter Full Name: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", full_name);

        cout << "Enter Username: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", username);

        cout << "Enter Password: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", password);

        cout << "Enter Date Of Birth: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", date_of_birth);

        cout << "Enter Gender: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", gender);

        cout << "Enter Description/Bio: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", description);

        cout << "Security Question: What is your favourite athelete?" << endl;
        fflush(stdin);
        scanf("%[^\n]s", security_question);
    }

    void storeInFile()
    {
        fstream f;
        f.open("usersinfo.dat", ios::binary | ios::app);

        if (f)
        {
            f.write(reinterpret_cast<char *>(this), sizeof(*this));
            f.close();
            cout << "\nInformation stored successfully" << endl;
            system("pause");
        }
        else
        {
            cout << "\nError Opening File" << endl;
        }
    }

    void displayAllUserInfo()
    {
        fstream f;
        f.open("usersinfo.dat", ios::binary | ios::in);

        if (f)
        {
            f.read(reinterpret_cast<char *>(this), sizeof(*this));
            while (f)
            {
                displayUserInfo();
                f.read(reinterpret_cast<char *>(this), sizeof(*this));
            }
            f.close();
            system("pause");
        }
        else
            cout << "\nError Opening File" << endl;
    }

    void displayUserInfo()
    {
        cout << "\nName: " << full_name << endl;
        cout << "Username: " << username << endl;
        cout << "Date Of Birth: " << date_of_birth << endl;
        cout << "Gender: " << gender << endl;
        cout << "Description/Bio: " << description << endl;
        cout << "Favourite Athele: " << security_question << endl;

        system("pause");
    }

    bool isValidInfo(char _username[], char _password[])
    {
        fstream f;
        f.open("usersinfo.dat", ios::in | ios::binary);

        if (f)
        {
            f.read(reinterpret_cast<char *>(this), sizeof(*this));
            while (f)
            {
                if ((!strcmp(username, _username)) && (!strcmp(password, _password)))
                {
                    f.close();
                    return true;
                }
                f.read(reinterpret_cast<char *>(this), sizeof(*this));
            }
            f.close();
            return false;
        }
        else
            cerr << "\nError Opening File" << endl;
    }
};
class Comment
{
private:
    char content[COMMENT_SIZE];
    char username[USERNAME_SIZE];

public:
    Comment() {
        strcpy(content, "");
        strcpy(username, "");
    }

    void setusername(const char *_username)
    {
        strncpy(username, _username, USERNAME_SIZE - 1);
        username[USERNAME_SIZE - 1] = '\0';
    }
    const char *getusername() { return username; }

    void setcontent(const char *_content)
    {
        strncpy(content, _content, CONTENT_SIZE - 1);
        content[CONTENT_SIZE - 1] = '\0';
    }
    const char *getcontent() { return content; }
};
class Post
{
private:
    char username[USERNAME_SIZE], title[TITLE_SIZE], content[CONTENT_SIZE];
    Comment comments[MAX_COMMENTS];
    int no_comments, no_likes, post_ID;

public:
    Post()
    {
        no_comments = 0;
        no_likes = 0;
    }
    Post(char uname[])
    {
        strcpy(username, uname);
        no_comments = 0;
        no_likes = 0;
    }

    // getter and setters

    void setusername(const char *_username)
    {
        strncpy(username, _username, USERNAME_SIZE - 1);
        username[USERNAME_SIZE - 1] = '\0';
    }
    const char *getusername(char *_username) { return username; }

    void settitle(const char *_title)
    {
        strncpy(title, _title, TITLE_SIZE - 1);
        title[TITLE_SIZE - 1] = '\0';
    }
    const char *gettitle(char *_title) { return title; }

    void setcontent(const char *_content)
    {
        strncpy(content, _content, CONTENT_SIZE - 1);
        content[CONTENT_SIZE - 1] = '\0';
    }
    const char *getcontent(char *_content) { return content; }

    void setno_comments(int _no_comments) { no_comments = _no_comments; }
    int getno_comments() { return no_comments; }

    void setno_likes(int _no_likes) { no_likes = _no_likes; }
    int getno_likes() { return no_likes; }

    void setpost_ID(int _post_ID) { post_ID = _post_ID; }
    int getpost_ID() { return post_ID; }

    void getPostData()
    {

        cout << "Enter Post ID: " << endl;
        fflush(stdin);
        scanf("%d", &post_ID);


        cout << "\nEnter Post Title: " << endl;
        fflush(stdin);
        scanf("%[^\n]s", title);

        string s;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter Post Content: (Enter + Ctrl-Z) to Exit" << endl;
        getline(cin, s, static_cast<char>(EOF));

        strcpy(content, s.c_str());
    }

    void displayPostData()
    {
        cout << "\nPost ID: " << post_ID << endl;
        cout << "UserName: " << username << endl;
        cout << "Post Title: " << title << endl;
        cout << "Post Content: " << "\n"
             << content;
        cout << "Likes: " << no_likes <<endl;
        if (no_comments)
        {
            cout << "Comments:" << endl;
            for (int i = 0; i < no_comments; i++)
            {
                cout << "\nUsername: " << comments[i].getusername() << endl;
                cout << "Comment: " << comments[i].getcontent()<< endl;
            }
        }
        else
        {
            cout << "(No Comments for this post)" << endl;
        }
    }

    void displayAllPostData()
    {
        fstream f;
        f.open("posts.dat", ios::binary | ios::in);

        if (f)
        {
            f.read(reinterpret_cast<char *>(this), sizeof(*this));
            while (f)
            {
                displayPostData();
                f.read(reinterpret_cast<char *>(this), sizeof(*this));
            }
            f.close();
            system("pause");
        }
        else
        {
            cout << "\nError Opening File" << endl;
        }
    }
    void storeInFile()
    {
        fstream f;
        f.open("posts.dat", ios::binary | ios::app);

        if (f)
        {
            f.write(reinterpret_cast<char *>(this), sizeof(*this));
            f.close();
            cout << "\nInformation stored successfully" << endl;
            system("pause");
        }
        else
        {
            cout << "\nError Opening File" << endl;
        }
    }
    void editPost()
    {
        char uname[USERNAME_SIZE];
        strcpy(uname, username);
        int id;
        cout << "Enter Post ID: ";
        fflush(stdin);
        scanf("%d", &id);

        fstream f;
        f.open("posts.dat", ios::binary | ios::in);
        if (f)
        {
            fstream ftemp;
            ftemp.open("temp.dat", ios::binary | ios::out);
            if (ftemp)
            {
                int found = 0;
                f.read(reinterpret_cast<char *>(this), sizeof(Post));
                while (f)
                {
                    if (post_ID == id && (!strcmp(uname, username)))
                    {
                        found = 1;
                        this->getPostData();
                    }
                    ftemp.write(reinterpret_cast<char *>(this), sizeof(Post));
                    f.read(reinterpret_cast<char *>(this), sizeof(Post));
                }
                f.close();
                ftemp.close();
                remove("posts.dat");
                rename("temp.dat", "posts.dat");
                if (!found)
                {
                    cout << "Error: Invalid ID, Or ID of other User" << endl;
                }
                else
                {
                    cout << "File has been edited successfully" << endl;
                }

                system("pause");
            }
            else
            {
                cout << "\nError Opening File" << endl;
            }
        }
        else
        {
            cout << "\nFILE not opened successfully" << endl;
        }
    }

    void addComment(){
        char uname[USERNAME_SIZE];
        strcpy(uname, username);
        int id;
        cout << "Enter Post ID: ";
        fflush(stdin);
        scanf("%d", &id);

        fstream f;
        f.open("posts.dat", ios::binary | ios::in);
        if (f)
        {
            fstream ftemp;
            ftemp.open("temp.dat", ios::binary | ios::out);
            if (ftemp)
            {
                int found = 0;
                f.read(reinterpret_cast<char *>(this), sizeof(Post));
                while (f)
                {
                    if (post_ID == id && (!strcmp(uname, username)))
                    {
                        found = 1;
                        char comment[COMMENT_SIZE];
                        cout<<"\nEnter Comment:"<<endl;
                        fflush(stdin);
                        scanf("%[^\n]s", comment);

                        comments[no_comments].setcontent(comment);
                        comments[no_comments].setusername(uname);
                        no_comments++;
                        
                    }
                    ftemp.write(reinterpret_cast<char *>(this), sizeof(Post));
                    f.read(reinterpret_cast<char *>(this), sizeof(Post));
                }
                f.close();
                ftemp.close();
                remove("posts.dat");
                rename("temp.dat", "posts.dat");
                if (!found)
                {
                    cout << "Error: Invalid ID" << endl;
                }
                else
                {
                    cout << "Comment has been added successfully" << endl;
                }

                system("pause");
            }
            else
            {
                cout << "\nError Opening File" << endl;
            }
        }
        else
        {
            cout << "\nFILE not opened successfully" << endl;
        }
    }

    void increaseLike(){
        int id;
        cout << "Enter Post ID: ";
        fflush(stdin);
        scanf("%d", &id);

        fstream f;
        f.open("posts.dat", ios::binary | ios::in);
        if (f)
        {
            fstream ftemp;
            ftemp.open("temp.dat", ios::binary | ios::out);
            if (ftemp)
            {
                int found = 0;
                f.read(reinterpret_cast<char *>(this), sizeof(Post));
                while (f)
                {
                    if (post_ID == id)
                    {
                        found = 1;
                        setno_likes(getno_likes() + 1);
                    }
                    ftemp.write(reinterpret_cast<char *>(this), sizeof(Post));
                    f.read(reinterpret_cast<char *>(this), sizeof(Post));
                }
                f.close();
                ftemp.close();
                remove("posts.dat");
                rename("temp.dat", "posts.dat");
                if (!found)
                {
                    cout << "Error: Invalid ID" << endl;
                }
                else
                {
                    cout << "Like has been added successfully" << endl;
                }

                system("pause");
            }
            else
            {
                cout << "\nError Opening File" << endl;
            }
        }
        else
        {
            cout << "\nFILE not opened successfully" << endl;
        }
    }

    void deletePost(){
        char uname[USERNAME_SIZE];
        strcpy(uname, username);
        int id;
        cout << "Enter Post ID: ";
        fflush(stdin);
        scanf("%d", &id);

        fstream f;
        f.open("posts.dat", ios::binary | ios::in);
        if (f)
        {
            fstream ftemp;
            ftemp.open("temp.dat", ios::binary | ios::out);
            if (ftemp)
            {
                int found = 0;
                f.read(reinterpret_cast<char *>(this), sizeof(Post));
                while (f)
                {
                    if (post_ID == id && (!strcmp(uname, username)))
                    {
                        found = 1;
                        f.read(reinterpret_cast<char *>(this), sizeof(Post));
                        continue;
                    }
                    ftemp.write(reinterpret_cast<char *>(this), sizeof(Post));
                    f.read(reinterpret_cast<char *>(this), sizeof(Post));
                }
                f.close();
                ftemp.close();
                remove("posts.dat");
                rename("temp.dat", "posts.dat");
                if (!found)
                {
                    cout << "Error: Invalid ID, Or ID of other User" << endl;
                }
                else
                {
                    cout << "Post has been deleted successfully" << endl;
                }

                system("pause");
            }
            else
            {
                cout << "\nError Opening File" << endl;
            }
        }
        else
        {
            cout << "\nFILE not opened successfully" << endl;
        }
    }
};

class ViewPostPage
{
private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
    }
    void display()
    {
        system("cls");
        cout << "This is This is View Post Page of The User" << endl;
        post.displayAllPostData();
        system("pause");
    }
};

class CreatePostPage
{
private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
        post.setusername(userinfo.get_username());
    }
    void display()
    {
        system("cls");
        cout << "This is This is Create Post Page of The User" << endl;
        post.getPostData();

        if (isUniqueID())
        {
            post.storeInFile();
        }
        else
        {
            cout << "Post Not created!!\nPost ID should be unique" << endl;
            system("pause");
        }

        system("pause");
    }

    bool isUniqueID()
    {
        bool isUnique = true;
        fstream f;
        f.open("posts.dat", ios::binary | ios::in);

        if (f)
        {
            Post p;
            f.read(reinterpret_cast<char *>(&p), sizeof(Post));
            while (f)
            {
                if (p.getpost_ID() == post.getpost_ID())
                {
                    isUnique = false;
                    break;
                }
                f.read(reinterpret_cast<char *>(&p), sizeof(Post));
            }
            f.close();
            return isUnique;
        }
    }
};

class EditPostPage
{

private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
        post.setusername(userinfo.get_username());
    }
    void display()
    {
        system("cls");
        cout << "This is This is Edit Post Page of The User" << endl;
        post.editPost();
        system("pause");
    }
};

class DeletePostPage
{

private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
        post.setusername(userinfo.get_username());
    }
    void display()
    {
        system("cls");
        cout << "This is This is Delete Post Page of The User" << endl;
        post.deletePost();
        system("pause");
    }
};

class AddCommentPage
{
private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
        post.setusername(userinfo.get_username());
    }
    void display()
    {
        system("cls");
        cout << "This is This is Add Comments Page of The User" << endl;
        post.addComment();
        system("pause");
    }
};

class AddLikePage
{
private:
    UserInfo userinfo;
    Post post;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
    }
    void display()
    {
        system("cls");
        cout << "This is This is Add Like Page of The User" << endl;
        post.increaseLike();
        system("pause");
    }
};

class YourInformationPage
{
private:
    UserInfo userinfo;

public:
    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
    }
    void display()
    {
        system("cls");
        cout << "This is This is Your Information Page of The User" << endl;
        userinfo.displayUserInfo();
        system("pause");
    }
};

class AccountDashboardPage
{

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
    AccountDashboardPage() {}
    AccountDashboardPage(UserInfo uinfo) : userinfo(uinfo) {}

    void setUserInfo(UserInfo uinfo)
    {
        userinfo = uinfo;
        viewpostPage.setUserInfo(userinfo);
        createpostPage.setUserInfo(userinfo);
        editpostPage.setUserInfo(userinfo);
        deletepostPage.setUserInfo(userinfo);
        addcommentPage.setUserInfo(userinfo);
        addlikePage.setUserInfo(userinfo);
        yourinformationPage.setUserInfo(userinfo);
    }

    void displayMenu()
    {

        system("cls");
        cout << "Welcome To Socialize" << endl;
        cout << "Account DashBoard For " << endl
             << endl;
        cout << "1. View All Posts" << endl;
        cout << "2. Create Post" << endl;
        cout << "3. Edit Post" << endl;
        cout << "4. Delete Post" << endl;
        cout << "5. Add Comment To Post" << endl;
        cout << "6. Add Like To Post" << endl;
        cout << "7. View Your Information" << endl;
        cout << "8. Logout Account" << endl;
        cout << "9. Exit" << endl;
    }

    void run()
    {
        while (true)
        {
            int choice;
            do
            {
                displayMenu();
                cout << "\nEnter your choice: ";
                choice = getch() - '0';
                switch (choice)
                {
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

class LoginPage
{
private:
    char username[USERNAME_SIZE], password[PASSWORD_SIZE];
    AccountDashboardPage accountdashboardpage;

public:
    void display()
    {
        system("cls");
        cout << "\nUsername: ";
        fflush(stdin);
        scanf("%[^\n]s", username);
        cout << "Password: ";
        fflush(stdin);
        scanf("%[^\n]s", password);

        UserInfo userinfo;

        if (userinfo.isValidInfo(username, password))
        {
            cout << "\nLogin Successful" << endl;
            accountdashboardpage.setUserInfo(userinfo);
            accountdashboardpage.run();
        }
        else
        {
            cout << "Login Not Successful" << endl;
        }

        system("pause");
    }
};

class SignupPage
{
private:
    UserInfo userinfo;

public:
    void display()
    {

        userinfo.getData();

        if (isUniqueUsername())
        {
            userinfo.storeInFile();
        }
        else
        {
            cout << "Username already exists" << endl;
            system("pause");
        }
    }

    bool isUniqueUsername()
    {
        bool isUnique = true;
        fstream f;
        f.open("usersinfo.dat", ios::binary | ios::in);

        if (f)
        {
            UserInfo uinfo;
            f.read(reinterpret_cast<char *>(&uinfo), sizeof(UserInfo));
            while (f)
            {
                if (!strcmp(uinfo.get_username(), userinfo.get_username()))
                {
                    isUnique = false;
                    break;
                }
                f.read(reinterpret_cast<char *>(&uinfo), sizeof(UserInfo));
            }
            f.close();
            return isUnique;
        }
        else
        {
            cout << "\nError Opening File" << endl;
        }
    }
};

class HelpPage
{
public:
    void display()
    {
        system("cls");
        cout << "This is help Page" << endl;
        cout << "you can further reach us on whatsapp for help" << endl;
        system("pause");
    }
};

class AboutPage
{
public:
    void display()
    {
        system("cls");
        cout << "This is about Page" << endl;
        cout << "This software is created by Farhan, Sabih and Saad" << endl;
        system("pause");
    }
};

class SocializeApp
{
private:
    LoginPage loginPage;
    SignupPage signupPage;
    HelpPage helpPage;
    AboutPage aboutPage;
    UserInfo uinfo;

public:
    void displayMenu()
    {
        system("cls");
        cout << "Welcome To Socialize" << endl
             << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Help" << endl;
        cout << "4. About" << endl;
        cout << "5. Display All Users" << endl;
        cout << "6. Exit" << endl;
    }

    void run()
    {
        while (true)
        {
            int choice;
            do
            {
                displayMenu();
                cout << "\nEnter your choice: ";
                choice = getch() - '0';
                switch (choice)
                {
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