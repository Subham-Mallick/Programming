int Solution::trap(const vector<int> &A) {

    vector<int> left(A.size());
    vector<int> right(A.size());
    int c = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        c = max( c,A[i] );
        left[i] = c;
    }
    c= INT_MIN;
    for(int i=A.size()-1;i>=0;i--)
    {
        c = max( c,A[i] );
        right[i] = c;
    }
    int ans =0;
    
    //
    
    for(int i=0;i<A.size();i++)
    {
        ans = ans + (min(left[i],right[i]) -A[i]);
    }
    return ans;
    
}
