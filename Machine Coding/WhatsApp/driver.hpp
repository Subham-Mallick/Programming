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
            
            UserChat userChat(sender,receiver,message);
            
            userChatVector.push_back(userChat);
            
        }
        
        vector<UserChat> getUserChatVector()
        {
            return getUserChatVector;
        }
        
        void setUserChatVector(vector<UserChat> userChatVector)
        {
            this.userChatVector = userChatVector;
        }
}