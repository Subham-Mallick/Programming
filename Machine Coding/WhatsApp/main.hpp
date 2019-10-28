int main()
{
    Driver run;    
    int option;
    do
    {
        cout<<"1.add user\n2.send message\n3.show user chat\n4.show all chat\n0. exit";
        cin>>option;
        
        switch(option)
        {
            case 1:
                string name,number;
                cout<<"Enter user name";
                cin>>name;
                cout<<"Enter user Number";
                cin>>number;
                User user(name,number);
                run.addUser(user);
                
            break;
            
            case 2:
                string sender,receiver,message;
                cout<<"Enter sender name";
                cin>>sender;
                cout<<"Enter receiver name";
                cin>>receiver;
                cout<<"Enter message";
                cin>>message;
                
                run.sendMessage(sender,receiver,message);
                
            break;
            
            case 3:
                
                
                
            break;
            
            case 4:
            break;
            
            default:
            break;
            
        }
        
        
        
    }while(option>=1 and option<=4);
}