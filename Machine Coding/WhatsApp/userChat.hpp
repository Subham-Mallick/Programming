#include<bits/stdc++.h>
#include "chat.hpp"
using namespace std;


class UserChat
{
    private:
        User chatOwner;
        User messageFrom;
        vector<Chat> chat;
    public:

        UserChat();

        UserChat(User chatOwner,User messageFrom,Chat chat)
        {
            this->chatOwner = chatOwner;
            this->messageFrom = messageFrom;
            this->chat.push_back(chat);
        }
        
        void setChatOwner(User chatOwner){ this->chatOwner = chatOwner; }
        
        void setMessageFrom(User messgeFrom){ this->messageFrom = messgeFrom; }
        
        void setMessage(Chat chat){ this->chat.push_back(chat); }

        User getChatOwner(){ return chatOwner; }

        User getMessageFrom(){ return messageFrom; }

        vector<Chat> getChat() { return chat; }
        
};