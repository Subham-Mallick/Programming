#include<bits/stdc++.h>
using namespace std;

class A
{
    ~A()
        {
            
        }
    public:
        friend void dest(A*); // function to avoid memeory leak
};

void dest(A* obj)
{
    delete obj;
}

int main()
{
    A a,b,c,d,e; // compiler error
    
    A* obj1 = new A;
}
