class User
{
    private:
        string userPhoneNumber;
        string userName;
    public:
    
        User(string userName,string userPhoneNumber)
        {
            this.userPhoneNumber = userPhoneNumber;
            this.userName = userName;
        }
        
        void setUserPhoneNumber(string userPhoneNumber)
        {
            this.userPhoneNumber = userPhoneNumber;
        }
        
        void setUserName(string userName)
        {
            this.userName = userName;
        }
                
        string getUserPhoneNumber()
        {
            return userPhoneNumber;
        }
        
        string getUserName()
        {
            return userName;
        }
}
