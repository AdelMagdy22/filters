// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text-Editor.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Abdelrahman Tarek Mohamed	20210206
// Author2 and ID and Group: Adel xxxxx
// Author3 and ID and Group: Roaa Talat Mohamed 20210138
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........


#include <iostream>
#include <fstream>
#include <string.h>
#include <regex>
using namespace std;

void newuser();

int main()
{
    char choose = ' ';
    while (choose != '0')
    {
        cout << "Ahlan ya user  " << endl;
        cout << "Please select what you want to do:  " << endl;
        cout << "1- New user" << endl;
        cout << "0- Exit" << endl;
        cin >>choose;
        if (choose == '1')
        {
            newuser();
        } else
        {
            cout << "See you later" << endl;
            return 0;
        }
     }
     return 0;
}


bool Email_check(string email)
{
     const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}

bool phone_check(string phone)
{
     const regex pattern("01[0125][0-9]{8}");
    return regex_match(phone,pattern);
}

bool username_check(string username)
{
     const regex pattern("[a-zA-Z0-9- ]+");
    return regex_match(username,pattern);
}

void newuser(){
    fstream login;
    login.open("login.text", ios::app );

    int x=0;
    char username[30];
    char password[30];
    //char newemail[127];
    char email[127];
    char phone[11];

    while(x==0){
        cin.ignore();
        cout <<"create a username: ";
        cin.getline(username,30);
        if(username_check(username))
        {
            cout <<"username created successfully"<<endl;
            login << username << '|';
            x=1;
        }
        else
            cout<<" invalid username "<<endl;
    }


    cout <<"create a password: ";
    cin.getline(password,30);
    login <<  password<< '|';

    while (x==1){
        cout<<"create an email: ";
        cin.getline(email,127);
        if(Email_check(email))
        {
            cout <<"email created successfully"<<endl;
            login<<email<<'|';
            x=2;
        }
        else
            cout<<" invalid email"<<endl;

    }
    while (x==2){
        cout <<"enter your phone number: ";
        cin>>phone;

        if(phone_check(phone))
        {
            cout << "right phone number";
            login<<phone<<'|'<<endl;
            x=3;
        }
        else
            cout<<"invalid phone number"<<endl;
    }






    /*login.open("login.text", ios::in );
    while(!login.eof())
    {
        login.getline(username, 30, '|');
        login.getline(password, 30, '|');
        login.getline(newemail , 64);
        if(strcmp(newemail, email)==0)
        {
            cout <<"This email already exists, try another one"<<endl;
            break;
        }else
        {
            login << 
        }
    }*/
}


