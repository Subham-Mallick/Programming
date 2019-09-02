int Solution::solve(vector<int> &A) {
    
    int e=0,o=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]%2==0)
            e++;
        else 
            o++;
    }
    return min(e,o);
}
