
/*
Count ways to express a number as sum of consecutive numbers

https://www.geeksforgeeks.org/count-ways-express-number-sum-consecutive-numbers/

desc:
sum of n consecutive numbers = ((first+last)*n)/2


first = (2 * (testCase) + n + -n*n)/(2*n)
*/

#include<bits/stdc++.h>
using namespace std;

int func(int A)
{
    int n=2;
    int count =0;
    
    while( 2*A + n - n*n > 0 )
    {
        float a = float(2*A + n - n*n)/float(2*n);
        
        if ( a - int(a) ==0 )
        {
            //cout<<a<<" "<<count<<endl;
            count++;
        }
        n++;
    }
    return count;
    
}

int main()
{
    cout<<func(100);
}