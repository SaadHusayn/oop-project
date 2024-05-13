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
#include <iomanip>
#include <cstring>
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

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string LIGHT_RED = "\033[91m";
const string LIGHT_GREEN = "\033[92m";
const string LIGHT_YELLOW = "\033[93m";
const string RESET_COLOR = "\033[0m";

void loading() {
    system("cls");
        cout << "\n\n\n\n\n\n";
        cout <<BLUE <<string(30, '-') <<GREEN << "Socialize: Where Every Connection Counts." <<BLUE <<string(30, '-') <<endl;
        cout <<GREEN << "\nLoading." ;
        for(int i = 0; i < 10; i++) {
            Sleep(100);
            cout <<BLUE << "." <<RESET_COLOR;
        }
}

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
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Signup Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Signup Post Page "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
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
        cout << '|' <<string(40, '-') <<'|' <<endl;
    }

    void storeInFile()
    {
        fstream f;
        f.open("usersinfo.dat", ios::binary | ios::app);

        if (f)
        {
            f.write(reinterpret_cast<char *>(this), sizeof(*this));
            f.close();
            cout <<LIGHT_GREEN << "\nInformation stored successfully" <<RESET_COLOR << endl;
            system("pause");
        }
        else
        {
            cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
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
            cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
    }

    void displayUserInfo()
    {

         system("cls");
        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) << '*' <<GREEN << "User Info" <<RESET_COLOR << '*' <<setw((totalWidth-(strlen("User Info"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' <<MAGENTA << "Name: " <<BLUE << full_name <<RESET_COLOR <<setw((totalWidth+1)-((strlen("Name: ")) + (strlen(full_name)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<MAGENTA << "Username: " <<BLUE << username <<RESET_COLOR <<setw((totalWidth+1)-((strlen("Username: ")) + (strlen(username))))  << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<MAGENTA << "Date Of Birth: " <<BLUE << date_of_birth <<RESET_COLOR <<setw((totalWidth+1)-((strlen("Date Of Birth: ")) + (strlen(date_of_birth)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<MAGENTA << "Gender: " <<BLUE << gender <<RESET_COLOR <<setw((totalWidth+1)-((strlen("Gender: ")) + (strlen(gender)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<MAGENTA << "Description/Bio: " <<BLUE << description <<RESET_COLOR<<setw((totalWidth+1)-((strlen("Description/Bio: ")) + (strlen(description)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<MAGENTA << "Favourite Athele: " <<BLUE << security_question <<RESET_COLOR <<setw((totalWidth+1)-((strlen("Favourite Athele: ")) + (strlen(security_question)))) << '|'<< endl;

        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;

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
        cout << '|' <<string(40, '-') <<'|' <<endl;

    }

    void displayPostData()
    {
        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << string(totalWidth, '-') <<endl;
        cout <<GREEN << "Post ID: " <<BLUE << post_ID <<RESET_COLOR <<endl; 
        cout <<GREEN << "UserName: " <<BLUE << username <<RESET_COLOR <<endl; 
        cout <<GREEN << "Post Title: " <<BLUE << title <<RESET_COLOR <<endl; 
        cout <<endl;
        cout <<GREEN <<string(4, '-') << "Post Content" <<string(4, '-') <<endl;
        cout <<BLUE << content <<RESET_COLOR <<endl;

        cout <<GREEN<< "LIKES: " <<BLUE << no_likes <<RESET_COLOR <<endl <<endl;
        if (no_comments)
        {
            cout <<GREEN << "COMMENTS: " << endl;
            for (int i = 0; i < no_comments; i++)
            {
                // cout << "Username: " << comments[i].getusername() << endl;
                // cout << "Comment: " << comments[i].getcontent()<< endl;
                cout <<GREEN <<comments[i].getusername() <<": " <<BLUE << comments[i].getcontent() <<RESET_COLOR << endl;
                //cout << "Comment: " << comments[i].getcontent()<< endl;
            }
        }
        else
        {
            cout <<BLUE << "(No Comments for this post)" << endl;
        }
        cout << string(totalWidth, '-') <<endl;
        cout <<endl <<endl;
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
            cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
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
            cout <<LIGHT_GREEN << "\nInformation stored successfully" <<RESET_COLOR << endl;
            system("pause");
        }
        else
        {
            cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
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
                    cout <<RED << "Error: Invalid ID, Or ID of other User" <<RESET_COLOR << endl;
                }
                else
                {
                    cout <<LIGHT_GREEN << "File has been edited successfully" <<RESET_COLOR << endl;
                }
                system("pause");
            }
            else
            {
                cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
            }
        }
        else
        {
            cout <<RED << "\nFILE not opened successfully" <<RESET_COLOR << endl;
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
                    cout <<RED << "Error: Invalid ID" <<RESET_COLOR << endl;
                }
                else
                {
                    cout <<LIGHT_GREEN << "Comment has been added successfully" <<RESET_COLOR << endl;
                }
                cout << '|' <<string(40, '-') <<'|' <<endl;
                system("pause");
            }
            else
            {
                cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
            }
        }
        else
        {
            cout <<RED << "\nFILE not opened successfully" <<RESET_COLOR << endl;
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
                    cout <<RED << "Error: Invalid ID" <<RESET_COLOR << endl;
                }
                else
                {
                    cout <<LIGHT_GREEN << "Like has been added successfully" <<RESET_COLOR << endl;
                }
                cout << '|' <<string(40, '-') <<'|' <<endl;
                system("pause");
            }
            else
            {
                cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
            }
        }
        else
        {
            cout <<RED << "\nFILE not opened successfully" <<RESET_COLOR << endl;
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
                    cout <<RED << "Error: Invalid ID, Or ID of other User" <<RESET_COLOR << endl;
                }
                else
                {
                    cout <<LIGHT_GREEN << "Post has been deleted successfully" <<RESET_COLOR << endl;
                }
                 cout << '|' <<string(40, '-') <<'|' <<endl;

                system("pause");
            }
            else
            {
                cout <<RED << "\nError Opening File" <<RESET_COLOR << endl;
            }
        }
        else
        {
            cout <<RED << "\nFILE not opened successfully" <<RESET_COLOR << endl;
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

        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << '|' << setw(16) <<'*' <<GREEN << "VIEW POST PAGE" <<RESET_COLOR <<'*' <<setw((totalWidth-(strlen("VIEW POST PAGE"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << string(totalWidth, '-') <<endl;

        cout <<MAGENTA << "This is the View Post Page of The User." <<RESET_COLOR << endl;
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
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Create Post Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Create Post Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        post.getPostData();

        if (isUniqueID())
        {
            post.storeInFile();
        }
        else
        {
            cout <<setw(10) <<'|' <<string(40,'-') << '|' <<endl;
            cout <<setw(10) <<'|' <<RED << "Post Not created!! " <<RESET_COLOR <<setw(40- strlen("Post Not created!!")) <<'|' << endl;
            cout <<setw(10) <<'|' <<RED << "Post ID should be unique " <<RESET_COLOR <<setw(40- strlen("Post ID should be unique")) <<'|' << endl;
            cout <<setw(10) <<'|' <<string(40,'-') << '|' <<endl;
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
        // cout << "This is This is Edit Post Page of The User" << endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN<<"Edit Post Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Edit Post Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
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
        // cout << "This is This is Delete Post Page of The User" << endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Delete Post Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Delete Post Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
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
        // cout << "This is This is Add Comments Page of The User" << endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Add Comment Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Add Comment Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
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
        //cout << "This is This is Add Like Page of The User" << endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Add Like Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("Add Like Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
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

        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) <<'*' <<GREEN << "----" << "SOCIALIZE" << "----" <<RESET_COLOR <<'*' <<setw((totalWidth-(strlen("SOCIALIZE"))-24)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) << '*' <<GREEN << "Account DashBoard For " <<RESET_COLOR << '*' <<setw((totalWidth-(strlen("Account DashBoard For "))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' <<BLUE << "1. View All Posts" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("1. View All Posts"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "2. Create Post" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("2. Create Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "3. Edit Post" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("3. Edit Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "4. Delete Post" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("4. Delete Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "5. Add Comment To Post" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("5. Add Comment To Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "6. Add Like To Post" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("6. Add Like To Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "7. View Your Information" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("7. View Your Information"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "8. Logout Account" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("8. Logout Account"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "9. Exit" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("9. Exit"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

    }

    void run()
    {
        while (true)
        {
            int choice;
            do
            {
                displayMenu();
                cout <<MAGENTA<< "\nEnter your choice: " <<BLUE;
                choice = getch() - '0';
                cout <<RESET_COLOR;
                switch (choice)
                {
                case 1:
                {
                    loading();
                    viewpostPage.display();
                    break;
                }
                case 2:
                {
                    loading();
                    createpostPage.display();
                    break;
                }
                case 3:
                {
                    loading();
                    editpostPage.display();
                    break;
                }
                case 4:
                {
                    loading();
                    deletepostPage.display();
                    break;
                }
                case 5:
                {
                    loading();
                    addcommentPage.display();
                    break;
                }
                case 6:
                {
                    loading();
                    addlikePage.display();
                    break;
                }
                case 7:
                {
                    loading();
                    yourinformationPage.display();
                    break;
                }
                case 8:
                {
                    loading();
                    // system("cls");
                    // cout << "\n\n\n\n\n\n";
                    // cout <<string(30, '-') << "Socialize: Where Every Connection Counts." <<string(30, '-') <<endl;
                    // cout << "\nLogging out." ;
                    // for(int i = 0; i < 10; i++) {
                    //     Sleep(100);
                    //     cout << ".";
                    // }
                    cout << endl;
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
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << '|' <<setw(5) <<'*' <<GREEN <<"Login Page " <<RESET_COLOR <<"*" <<setw(40- (strlen("login Post Page "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout <<BLUE << "\nUsername: ";
        fflush(stdin);
        scanf("%[^\n]s", username);
        cout <<BLUE << "Password: " ;
        fflush(stdin);
        scanf("%[^\n]s", password);
        cout <<RESET_COLOR << '|' <<string(40, '-') <<'|' <<endl;


        UserInfo userinfo;

        if (userinfo.isValidInfo(username, password))
        {
            loading();
            cout << "\n\n" <<GREEN << "Login Successful." <<RESET_COLOR;
            for(int i = 0; i < 5; i++) {
                Sleep(100);
                cout << ".";
            }
            accountdashboardpage.setUserInfo(userinfo);
            accountdashboardpage.run();
        }
        else
        {
            cout <<'|' <<string(40,'-') << '|' <<endl;
            cout <<'|' <<RED << "Login Failed " <<RESET_COLOR <<setw(40- strlen("Login Failed")) <<'|' << endl;
            cout <<'|' <<RED << "Incorrect username or password " <<RESET_COLOR <<setw(40- strlen("Incorrect username or password")) <<'|'  <<endl;
            cout <<'|' <<RED << "Try Again. " <<RESET_COLOR <<setw(40- strlen("Try Again.")) <<'|' <<endl;
            cout <<'|' <<string(40,'-') << '|' <<endl;
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
            cout <<setw(10) <<'|' <<string(40,'-') << '|' <<endl;
            cout <<setw(10) <<'|' <<RED << "Username already exists " <<RESET_COLOR <<setw(40- strlen("Username already exists")) <<'|' << endl;
            cout <<setw(10) <<'|' <<string(40,'-') << '|' <<endl;
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

        const int totalWidth = 62; 
        const int colWidth = 20;

        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(25) << '*' <<GREEN << "HELP" <<RESET_COLOR << '*' <<setw((totalWidth-(strnlen("HELP",100))-25)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' <<BLUE << "You can further reach us on whatsapp for help or email us for " <<RESET_COLOR <<setw((totalWidth+1)-(strlen("You can further reach us on whatsapp for help or email us for "))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "any query at socialize.team@gamil.com " <<RESET_COLOR <<setw((totalWidth+1)-(strlen("any query at socialize.team@gamil.com "))) << '|'<< endl;
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;

        system("pause");
    }
};

class AboutPage
{
public:
    void display()
    {
        system("cls");
        const int totalWidth = 62;
        const int colWidth = 25;
        
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(22) << '*' <<GREEN << "About Page" <<RESET_COLOR<< '*' <<setw((totalWidth-(strlen("About Page"))-22)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' <<BLUE << "Socialize is a platform where you can create posts, like, " <<RESET_COLOR<<setw((totalWidth+1)-(strlen("Socialize is a platform where you can create posts, like, "))) << '|' <<endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "comment, and connect with others in a friendly community" <<RESET_COLOR<<setw((totalWidth+1)-(strlen("comment, and connect with others in a friendly community"))) << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(totalWidth+1) << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(totalWidth+1) << '|' <<endl;

        cout << setw(colWidth-9) << '|' <<BLUE << "Created by Farhan, Sabih and Saad" <<RESET_COLOR<<setw((totalWidth+1)-(strlen("Created by Farhan, Sabih and Saad"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<setw(totalWidth-6) <<right <<BLUE << "Version 1.0" <<RESET_COLOR <<"|" <<endl; 
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        
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
        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) << '*' <<GREEN << "Welcome To Socialize" <<RESET_COLOR << '*' <<setw((totalWidth-(strlen("Welcome To Socialize"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;
             //<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "1. Login" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("1. Login"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "2. Signup" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("2. Signup"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "3. Help" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("3. Help"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "4. About" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("4. About"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "5. Display All Users" <<RESET_COLOR <<setw((totalWidth+1)-((strlen("5. Display All Users")))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<BLUE << "6. Exit" <<RESET_COLOR <<setw((totalWidth+1)-(strlen("6. Exit"))) << '|'<< endl;
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;

    }

    void run()
    {
        loading();

        while (true)
        {
            int choice;
            do
            {
                displayMenu();
                cout <<MAGENTA << "\nEnter your choice: " <<BLUE;
                choice = getch() - '0';
                cout << RESET_COLOR;
                switch (choice)
                {
                case 1:
                {
                    loading();
                    loginPage.display();
                    break;
                }
                case 2:
                {
                    loading();
                    signupPage.display();
                    break;
                }
                case 3:
                {
                    loading();
                    helpPage.display();
                    break;
                }
                case 4:
                {
                    loading();
                    aboutPage.display();
                    break;
                }
                case 5:
                {
                    loading();
                    uinfo.displayAllUserInfo();
                    break;
                }
                case 6:
                {
                    loading();
                    // system("cls");
                    // cout << "\n\n\n\n\n\n";
                    // cout <<string(30, '-') << "Socialize: Where Every Connection Counts." <<string(30, '-') <<endl;
                    // cout << "\nLoading." ;
                    // for(int i = 0; i < 10; i++) {
                    //     Sleep(100);
                    //     cout << ".";
                    // }
                    Sleep(100);
                    exit(0);
                }
                }
            } while (choice < 1 || choice > 6);
        }
    }
};

#endif