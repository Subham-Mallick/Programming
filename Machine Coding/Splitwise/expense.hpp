#include "Split.hpp"

class Expense
{
    private:
        string expenseId;
        double expenseAmmount;
        User paidBy;
        vector<Split> expenseSplit;
        ExpenseInfo expenseInfo;
    public:
        Expense(double expenseAmmount,User paidBy,vector<Split> expenseSplit,ExpenseInfo expenseInfo)
        {
            this.expenseAmmount = expenseAmmount;
            this.paidBy=paidBy;
            this.expenseSplit = expenseSplit;
            this.expenseInfo = expenseInfo;
        }
        
        void setExpenseId(string expenseId) { this.expenseId = expenseId; }
        void setExpenseAmmount(double expenseAmmount) { this.expenseAmmount = expenseAmmount; }
        void setPaidBy(User paidBy) { this.paidBy = paidBy; }
        void setExpenseSplit(vector<Split> expenseSplit) { this.expenseSplit = expenseSplit; }
        void setExpenseInfo(ExpenseInfo expenseInfo) { this.expenseInfo = expenseInfo; }
        
        string getExpenseId() { return expenseId; }
        double getExpenseAmmount() { return expenseAmmount; }
        User getPaidBy() { return paidBy; }
        vector<Split> getExpenseSplit() { return expenseSplit; }
        ExpenseInfo getExpenseInfo() { return expenseInfo; }   
            
        virtual bool validate();
}

class EqualExpense
{
    public:
        EqualExpense(double expenseAmmount,User paidBy,vector<Split> expenseSplit,ExpenseInfo expenseInfo) : 
        Expense(expenseAmmount,paidBy,expenseSplit,expenseInfo)
        {
            
        }
        
        bool validate()
        {
            
        }
};

class ExactExpense
{
   public:
        ExactExpense(double expenseAmmount,User paidBy,vector<Split> expenseSplit,ExpenseInfo expenseInfo) : 
        Expense(expenseAmmount,paidBy,expenseSplit,expenseInfo)
        {
            
        }
        
        bool validate()
        {
            
        } 
};

class PercentageExpense
{
    public:
        PercentageExpense(double expenseAmmount,User paidBy,vector<Split> expenseSplit,ExpenseInfo expenseInfo) : 
        Expense(expenseAmmount,paidBy,expenseSplit,expenseInfo)
        {
            
        }
        
        bool validate()
        {
            
        }
};




























