vector<int> Solution::solve(vector<int> &A) {
    
    int c = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=0)
        {
            swap(A[c++],A[i]);
        }
    }
    return A;
    
}