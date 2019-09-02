vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans;
    
    if( A==0 )
        return ans;
    
    vector<int> v;
    v.push_back(1);
    ans.push_back(v);
    
    for(int i=1;i<A;i++)
    {
        vector<int> v;
        v.push_back(1);
        
        for(int j=1;j<i;j++)
        {
            v.push_back( ans[i-1][j] + ans[i-1][j-1] );
        }
        
        v.push_back(1);
        ans.push_back(v);
    }
    
    
    return ans;
    
}
