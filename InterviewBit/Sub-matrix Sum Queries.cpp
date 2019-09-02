vector<int> Solution::solve(vector<vector<int> > &a, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    vector<vector<int> > A = a;
    long long mod = 1000000007;
    int r = A.size();
    int c = A[0].size();
    //row prefix sum
    
  
    for(int i=0;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            A[i][j] = (A[i][j-1] + A[i][j])%mod;
        }
    }
    //col prefix sum
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            A[i][j] = (A[i-1][j] + A[i][j])%mod;
        }
    }
    
    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<c;j++)
    //         cout<<A[i][j]<<"-";
    // }
    
    vector<int> ans;
    
    for(int tc=0;tc<B.size();tc++)
    {
        
        int tli = B[tc]-1;
        int tlj = C[tc]-1;
        int bri = D[tc]-1;
        int brj = E[tc]-1;
        
        
        int res = A[bri][brj];
        
        if(tli > 0)
        {
            res = (res%mod - (A[tli-1][brj])%mod + mod)%mod;
        }
        
        if(tlj > 0)
        {
            res = (res%mod - (A[bri][tlj-1])%mod + mod)%mod;
        }
        
        if(tli >0 and tlj > 0)
        {
            res = (res%mod + (A[tli-1][tlj-1])%mod + mod )%mod;
        }
        
        ans.push_back((res%mod+mod)%mod);
        
    }
    
    
    
    return ans;
    
}
