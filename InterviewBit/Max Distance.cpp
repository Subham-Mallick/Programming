int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int ans = -1;
    vector<int>lmin(A.size());
    vector<int>rmax(A.size());
    lmin[0] = A[0];
    rmax[n-1] = A[n-1];
    for(int i=1;i<n;i++)
    {
        lmin[i] = min(lmin[i-1],A[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        rmax[i] = max(A[i],rmax[i+1]);
    }
    
    int i=0,j=0;
    while(i<n and j<n)
    {
        if(lmin[i] <= rmax[j])
        {
            ans  = max(ans,j-i);
            j++;
        }
        else
            i++;
    }
    
    
    return ans;
}
