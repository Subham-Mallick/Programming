#include "user.hpp"

class Split
{
    private:
        User userId;
    protected: 
        double splitAmmount;
    public:    
        Split(User userId) { this.userId = userId; }
        
        void setUserId(User userId) { this.userId = userId; }
        void setSplitAmmount(double splitAmmount) { this.splitAmmount = splitAmmount; }
        
        User getUserId() { return userId; }
        double getSplitAmmount() { return splitAmmount; }
};

class EqualSplit: public Split
{
    public:
        EqualSplit(User uerId):Split(userId)
        {}
};

class ExactSplit: public Split
{
    public:
        ExactSplit(User uerId,double splitAmmount):Split(userId)
        {
            this.splitAmmount = splitAmmount;
        }
};

class PercentageSplit: public Split
{
    private:
        double percentage;
    public:
        PercentageSplit(User uerId,double percentage):Split(userId)
        {
            this.percentage = percentage;
        }
        void setPercentage(double percentage) { this.percentage = percentage; }
        
        double getPercentage() { return percentage; }
};











