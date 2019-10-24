class ExpenseInfo
{
    private:
        string expenseName;
        string expenseNote;
        string expenseImage;
    public:
        void setExpenseName(string expenseName) { this.expenseName = expenseName; }
        void setExpenseNote(string expenseNote) { this.expenseNote = expenseNote; }
        void setExpenseImage(string expenseImage) { this.expenseImage = expenseImage; }
        
        string getExpenseName() { return expenseName; }
        string getExpenseNote() { return expenseNote; }
        string getExpenseImage() { return expenseImage; } 
};