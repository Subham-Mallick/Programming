class UserChat
{
    private:
        User chatOwner;
        User messgeFrom;
        string message;
    public:
        UserChat(User chatOwner,User messgeFrom,string message)
        {
            this.chatOwner = chatOwner;
            this.messgeFrom = messgeFrom;
            this.message = message;
        }
        
        void setChatOwner(User chatOwner)
        {
            this.chatOwner = chatOwner;
        }
        
        void setMessageFrom(User messgeFrom)
        {
            this.messgeFrom = messgeFrom;
        }
        
        void setMessage(string message)
        {
            this.message = message;
        }
        
}