#include<bits/stdc++.h>
using namespace std;

class A
{
    
    void* operator new(size_t sz); //new operator is overloaded and in private part
        
    public:
        static int objCount;
        A()
        {
            objCount++;
        }
        ~A()
        {
            objCount--;
        }
};

int A::objCount = 0;


int main()
{
    A a,b,c,d,e;
    
    A* obj1 = new A; //gives compiler error
    
    cout<<A::objCount;
}