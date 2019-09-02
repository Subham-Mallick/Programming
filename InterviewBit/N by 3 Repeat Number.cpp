/*
You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space. If so, return the integer. If not, return -1. If there are multiple solutions, return any one.  Example :
Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
*/

int Solution::repeatedNumber(const vector<int> &a) {
   
    int c1 = 0, c2 = 0;
    int n1 = INT_MIN, n2 = INT_MIN;
    int n = a.size();
    for( int i=0;i<a.size();i++ )
    {
        
        if(a[i]==n1){c1++;}
        else if( a[i] == n2 ){c2++;}
        else if(c1==0){n1 = a[i];c1++;}
        else if(c2==0){n2 = a[i];c2++;}
        else{c1--;c2--;}
        
    }
    c1 =0,c2=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==n1)
            c1++;
        else if(a[i]==n2)
            c2++;
    }
    if(c1>n/3)
        return n1;
    
    if(c2 > n/3)
        return n2;
    
    return -1;
    
    
    
    
}
