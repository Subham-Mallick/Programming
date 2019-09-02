/*Given an unsorted integer array, find the first missing positive integer. Example: Given [1,2,0] return 3, [3,4,-1,1] return 2,  [-8, -7, -6] returns 1  Your algorithm should run in O(n) time and use constant space.*/

int Solution::firstMissingPositive(vector<int> &A) {
    for(int i=0;i<A.size();)
    {
        //negetive , element more than size , its in its place , same numbers
        
        if(A[i] < 1 || A[i]>=A.size() || A[i] == i+1 || A[i] == A[ A[i]-1 ] )
        {
            i++;
            continue;
        }
        swap(A[i],A[ A[i]-1 ]);
        
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=i+1) return i+1;
    }
    
    //everything is in place return largest +1 
    return A.size()+1;
    
    
}
