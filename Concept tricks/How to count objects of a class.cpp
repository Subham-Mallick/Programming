#include<bits/stdc++.h>
using namespace std;

class A
{
    
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
    
    A* obj1 = new A;
    
    cout<<A::objCount;
}