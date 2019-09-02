void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i;
    for(i=A.size()-1;i>=1;i--)
    {
        if(A[i-1] < A[i])
            break;   
    }
    
    if(i==0)
        return sort(A.begin(),A.end());

    int p = i-1;
    int s;
    for(int i=A.size()-1;i>p;i--)
    {
        if(A[i]>A[p])
        {
            s = i;
            break;
        }
    }
    
    swap(A[p], A[s] );
    
    reverse(A.begin()+p+1,A.end());

    
}
