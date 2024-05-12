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

void loading() {
    system("cls");
        cout << "\n\n\n\n\n\n";
        cout <<string(30, '-') << "Socialize: Where Every Connection Counts." <<string(30, '-') <<endl;
        cout << "\nLoading." ;
        for(int i = 0; i < 10; i++) {
            Sleep(100);
            cout << ".";
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
        cout << '|' <<setw(5) <<'*' <<"Signup Page " <<"*" <<setw(40- (strlen("Signup Post Page "))) <<'|' <<endl;
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

         system("cls");
        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << setw(colWidth-9) << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) << '*' << "User Info" << '*' <<setw((totalWidth-(strlen("User Info"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' << "Name: " << full_name <<setw((totalWidth+1)-((strlen("Name: ")) + (strlen(full_name)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "Username: " << username <<setw((totalWidth+1)-((strlen("Username: ")) + (strlen(username))))  << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "Date Of Birth: " << date_of_birth <<setw((totalWidth+1)-((strlen("Date Of Birth: ")) + (strlen(date_of_birth)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "Gender: " << gender <<setw((totalWidth+1)-((strlen("Gender: ")) + (strlen(gender)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "Description/Bio: " << description <<setw((totalWidth+1)-((strlen("Description/Bio: ")) + (strlen(description)))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "Favourite Athele: " << security_question <<setw((totalWidth+1)-((strlen("Favourite Athele: ")) + (strlen(security_question)))) << '|'<< endl;

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
        cout << "Post ID: " << post_ID <<endl; 
        cout << "UserName: " << username <<endl; 
        cout << "Post Title: " << title <<endl; 
        cout <<endl;
        cout <<string(4, '-') << "Post Content" <<string(4, '-') <<endl;
        cout << content <<endl;

        cout << "LIKES: " << no_likes <<endl <<endl;
        if (no_comments)
        {
            cout << "COMMENTS: " << endl;
            for (int i = 0; i < no_comments; i++)
            {
                // cout << "Username: " << comments[i].getusername() << endl;
                // cout << "Comment: " << comments[i].getcontent()<< endl;
                cout <<comments[i].getusername() <<": " << comments[i].getcontent() << endl;
                //cout << "Comment: " << comments[i].getcontent()<< endl;
            }
        }
        else
        {
            cout << "(No Comments for this post)" << endl;
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
                    if (post_ID == id)
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
                cout << '|' <<string(40, '-') <<'|' <<endl;
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
                cout << '|' <<string(40, '-') <<'|' <<endl;
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
                 cout << '|' <<string(40, '-') <<'|' <<endl;

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

        const int totalWidth = 62;
        const int colWidth = 20;
        
        cout << '+' << string(totalWidth, '-') << '+' <<endl;
        cout << '|' << setw(16) <<'*' << "VIEW POST PAGE" <<'*' <<setw((totalWidth-(strlen("VIEW POST PAGE"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << string(totalWidth, '-') <<endl;

        cout << "This is the View Post Page of The User." << endl;
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
        cout << '|' <<setw(5) <<'*' <<"Create Post Page " <<"*" <<setw(40- (strlen("Create Post Page      "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        post.getPostData();

        if (isUniqueID())
        {
            post.storeInFile();
        }
        else
        {
            cout <<setw(10) <<'|' <<string(40,'-') << '|' <<endl;
            cout <<setw(10) <<'|' << "Post Not created!! " <<setw(40- strlen("Post Not created!!")) <<'|' << endl;
            cout <<setw(10) <<'|' << "Post ID should be unique " <<setw(40- strlen("Post ID should be unique")) <<'|' << endl;
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
        cout << '|' <<setw(5) <<'*' <<"Edit Post Page " <<"*" <<setw(40- (strlen("Edit Post Page      "))) <<'|' <<endl;
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
        cout << '|' <<setw(5) <<'*' <<"Delete Post Page " <<"*" <<setw(40- (strlen("Delete Post Page      "))) <<'|' <<endl;
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
        cout << '|' <<setw(5) <<'*' <<"Add Comment Page " <<"*" <<setw(40- (strlen("Add Comment Page      "))) <<'|' <<endl;
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
        cout << '|' <<setw(5) <<'*' <<"Add Like Page " <<"*" <<setw(40- (strlen("Add Like Page      "))) <<'|' <<endl;
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
        cout << setw(colWidth-9) << '|' << setw(16) <<'*' << "----" << "SOCIALIZE" << "----" <<'*' <<setw((totalWidth-(strlen("SOCIALIZE"))-24)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(16) << '*' << "Account DashBoard For " << '*' <<setw((totalWidth-(strlen("Account DashBoard For "))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' << "1. View All Posts" <<setw((totalWidth+1)-(strlen("1. View All Posts"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "2. Create Post" <<setw((totalWidth+1)-(strlen("2. Create Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "3. Edit Post" <<setw((totalWidth+1)-(strlen("3. Edit Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "4. Delete Post" <<setw((totalWidth+1)-(strlen("4. Delete Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "5. Add Comment To Post" <<setw((totalWidth+1)-(strlen("5. Add Comment To Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "6. Add Like To Post" <<setw((totalWidth+1)-(strlen("6. Add Like To Post"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "7. View Your Information" <<setw((totalWidth+1)-(strlen("7. View Your Information"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "8. Logout Account" <<setw((totalWidth+1)-(strlen("8. Logout Account"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "9. Exit" <<setw((totalWidth+1)-(strlen("9. Exit"))) << '|'<< endl;
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
                cout << "\nEnter your choice: ";
                choice = getch() - '0';
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
        cout << '|' <<setw(5) <<'*' <<"Login Page " <<"*" <<setw(40- (strlen("login Post Page "))) <<'|' <<endl;
        cout << '|' <<string(40, '-') <<'|' <<endl;
        cout << "\nUsername: ";
        fflush(stdin);
        scanf("%[^\n]s", username);
        cout << "Password: ";
        fflush(stdin);
        scanf("%[^\n]s", password);
        cout << '|' <<string(40, '-') <<'|' <<endl;


        UserInfo userinfo;

        if (userinfo.isValidInfo(username, password))
        {
            system("cls");
            cout << "\n\n\n\n\n\n";
            cout <<string(30, '-') << "Socialize: Where Every Connection Counts." <<string(30, '-') <<endl;
            cout << "\nLoading." ;
            for(int i = 0; i < 5; i++) {
                Sleep(100);
                cout << ".";
            }
            cout << "\n\n" << "Login Successful." ;
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
            cout <<'|' << "Login Failed " <<setw(40- strlen("Login Failed")) <<'|' << endl;
            cout <<'|' << "Incorrect username or password " <<setw(40- strlen("Incorrect username or password")) <<'|'  <<endl;
            cout <<'|'<< "Try Again. " <<setw(40- strlen("Try Again.")) <<'|' <<endl;
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
            cout <<setw(10) <<'|' << "Username already exists " <<setw(40- strlen("Username already exists")) <<'|' << endl;
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
        cout << setw(colWidth-9) << '|' << setw(25) << '*' << "HELP" << '*' <<setw((totalWidth-(strnlen("HELP",100))-25)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' << "You can further reach us on whatsapp for help or email us for " <<setw((totalWidth+1)-(strlen("You can further reach us on whatsapp for help or email us for "))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "any query at socialize.team@gamil.com " <<setw((totalWidth+1)-(strlen("any query at socialize.team@gamil.com "))) << '|'<< endl;
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
        cout << setw(colWidth-9) << '|' << setw(22) << '*' << "About Page" << '*' <<setw((totalWidth-(strlen("About Page"))-22)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;

        cout << setw(colWidth-9) << '|' << "Socialize is a platform where you can create posts, like, " <<setw((totalWidth+1)-(strlen("Socialize is a platform where you can create posts, like, "))) << '|' <<endl;
        cout << setw(colWidth-9) << '|' << "comment, and connect with others in a friendly community" <<setw((totalWidth+1)-(strlen("comment, and connect with others in a friendly community"))) << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(totalWidth+1) << '|' <<endl;
        cout << setw(colWidth-9) << '|' << setw(totalWidth+1) << '|' <<endl;

        cout << setw(colWidth-9) << '|' << "Created by Farhan, Sabih and Saad" <<setw((totalWidth+1)-(strlen("Created by Farhan, Sabih and Saad"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' <<setw(totalWidth+1) <<right << "Version 1.0|" <<endl; //<<setw((totalWidth+1)-(strlen("Created by Farhan, Sabih and Saad"))) << '|'<< endl;
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
        cout << setw(colWidth-9) << '|' << setw(16) << '*' << "Welcome To Socialize" << '*' <<setw((totalWidth-(strlen("Welcome To Socialize"))-16)) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << string(totalWidth, '-') << '|' <<endl;
             //<< endl;
        cout << setw(colWidth-9) << '|' << "1. Login" <<setw((totalWidth+1)-(strlen("1. Login"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "2. Signup" <<setw((totalWidth+1)-(strlen("2. Signup"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "3. Help" <<setw((totalWidth+1)-(strlen("3. Help"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "4. About" <<setw((totalWidth+1)-(strlen("4. About"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "5. Display All Users" <<setw((totalWidth+1)-(strlen("5. Display All Users"))) << '|'<< endl;
        cout << setw(colWidth-9) << '|' << "6. Exit" <<setw((totalWidth+1)-(strlen("6. Exit"))) << '|'<< endl;
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
                cout << "\nEnter your choice: ";
                choice = getch() - '0';
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