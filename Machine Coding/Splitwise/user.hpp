class User
{
    private:
        string userId;
        string userName;
        string userEmail;
        string userMobile;
    public:
    
        User(string userId,string userName,string userEmail,string userMobile)
        {
            this.userId = userId;
            this.userName = userName;
            this.userEmail = userEmail;
            this.userMobile = userMobile;
        }

        string getUserId(){return userId;}
        string getUserName(){return userName;}  
        string getUserEmail(){return userEmail;}
        string getUserMobile(){return userMobile;}
        
        void setUserId(string userId){this.userId = userId;}
        void setUserName(string userName){this.userName = userName;}  
        void setUserEmail(string userEmail){this.userEmail = userEmail;}
        void setUserMobile(string userMobile){this.userMobile = userMobile;}
};