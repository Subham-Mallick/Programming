#include<bits/stdc++.h>
#include "userChat.hpp"
using namespace std;


class Driver
{
    private:
        map<User,string> userMapping;
        vector<UserChat> userChatVector;
    public:
        //validateUser();
        void addUser(User user)
        {
            userMapping[user] = user.getUserName();
        }
        
        User findUserUsingString(string userName)
        {
            for(auto it=userMapping.begin();it!=userMapping.end();it++)
            {
                if(it->second == userName)
                    return it->first;
            }
        }

        void sendMessage(string userFrom,string userTo,string message)
        {            
            User sender = findUserUsingString(userFrom);
            User receiver = findUserUsingString(userTo);
            Chat chat(message,sender);

            for(UserChat userChat:userChatVector)
            {
                if(
                    (userChat.getChatOwner().getUserName()== sender.getUserName() and userChat.getMessageFrom().getUserName()== receiver.getUserName())
                    or
                    (userChat.getChatOwner().getUserName()== receiver.getUserName() and userChat.getMessageFrom().getUserName()== sender.getUserName())
                )
                {
                    userChat.getChat().push_back(chat);
                    return;
                }
            }

            
            UserChat userChat(sender,receiver,chat);
            
            userChatVector.push_back(userChat);
        }
        
        vector<UserChat> getUserChatVector()
        {
            return userChatVector;
        }
        
        void setUserChatVector(vector<UserChat> userChatVector)
        {
            this->userChatVector = userChatVector;
        }

        string getAllMessageOfUser(string userName)
        {
            User sender = findUserUsingString(userName);
            vector<UserChat> userChats = getUserChatVector();
            vector<vector<Chat> > allChatOfUser;
            string solution="";

            for(auto userChat:userChats)
            {
                if(userChat.getChatOwner().getUserName() == sender.getUserName() or  userChat.getMessageFrom().getUserName() == sender.getUserName() )
                {
                    allChatOfUser.push_back(userChat.getChat());
                }
            }

            for(int i=0;i<allChatOfUser.size();i++)
            {
                for(int j=0;allChatOfUser[i].size();j++)
                {
                    solution += allChatOfUser[i][j].getUser().getUserName()+" : "+allChatOfUser[i][j].getMessage()+"\n";
                }
                solution += "\n---------CHAT ENDED---------\n";
            }
            return solution;
        }

        string getAllMessageOfUserWithAnotherUser(string senderOfMessage,string receiverOfMessage)
        {
            User sender = findUserUsingString(senderOfMessage);
            User receiver = findUserUsingString(receiverOfMessage);
            vector<UserChat> userChats = getUserChatVector();
            vector<vector<Chat> > allChatOfUser;
            string solution="";

            for(auto userChat:userChats)
            {
                if(userChat.getChatOwner().getUserName() == sender.getUserName() and userChat.getMessageFrom().getUserName() == receiver.getUserName() or
                userChat.getMessageFrom().getUserName() == sender.getUserName() and userChat.getChatOwner().getUserName() == receiver.getUserName() )
                {
                    allChatOfUser.push_back(userChat.getChat());
                }
            }

            for(int i=0;i<allChatOfUser.size();i++)
            {
                for(int j=0;allChatOfUser[i].size();j++)
                {
                    solution += allChatOfUser[i][j].getUser().getUserName()+" : "+allChatOfUser[i][j].getMessage()+"\n";
                }
                solution += "\n---------CHAT ENDED---------\n";
            }
            return solution;
        }
};