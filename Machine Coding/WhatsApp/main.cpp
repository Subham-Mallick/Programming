#include<bits/stdc++.h>
#include "driver.hpp"
using namespace std;

int main()
{
    Driver run;    
    int option;
    do
    {
        cout<<"1.add user\n2.send message\n3.show user's chat with everyone\n4. show user chat with another user\n0. exit";
        cin>>option;
        string name,number;
        string sender,receiver,message;
        User* user;
        switch(option)
        {
            case 1:
                
                cout<<"Enter user name";
                cin>>name;
                cout<<"Enter user Number";
                cin>>number;
                user = new User(name,number);
                run.addUser(*user);

            break;
            
            case 2:
                
                cout<<"Enter sender name";
                cin>>sender;
                cout<<"Enter receiver name";
                cin>>receiver;
                cout<<"Enter message";
                cin>>message;
                
                run.sendMessage(sender,receiver,message);
                
            break;
            
            case 3:
                cout<<"Enter sender name";
                cin>>sender;
                cout<<run.getAllMessageOfUser(sender);
            break;
            
            case 4:
                cout<<"Enter sender name";
                cin>>sender;
                cout<<"Enter receiver name";
                cin>>receiver;

                cout<<run.getAllMessageOfUserWithAnotherUser(sender,receiver);


            break;
            
            default:
            break;
            
        }
        
        
        
    }while(option>=1 and option<=4);
}