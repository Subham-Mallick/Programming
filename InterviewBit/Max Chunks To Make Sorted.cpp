int Solution::solve(vector<int> &A) {
    
    int ans =0;
    int maxS = -1;
    for(int i=0;i<A.size();i++)
    {
        maxS = max(maxS,A[i]);
        if(maxS==i)
            ans++;
    }
    return ans;
    
}
