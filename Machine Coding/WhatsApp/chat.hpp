#include<bits/stdc++.h>
#include "user.hpp"
using namespace std;

class Chat
{
    private:
        string message;
        User sender;
    public:

        Chat();

        Chat(string message,User sender)
        {
            this->message = message;
            this->sender = sender;
        }

        void setMessage(string message){ this->message = message; }
        string getMessage(){ return message; }

        void setUser(User sender){ this->sender = sender; }
        User getUser() { return sender; }
};