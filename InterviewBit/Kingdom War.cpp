
int Solution::solve(vector<vector<int> > &A) {

    vector<vector<int> > v = A;
    
    int r = v.size();
    int c = v[0].size();
    
    for(int i=r-2;i>=0;i--)
    {
        v[i][c-1] = v[i][c-1] + v[i+1][c-1];
    }
    
    for(int j=c-2;j>=0;j--)
    {
        v[r-1][j] = v[r-1][j] + v[r-1][j+1];
    }

    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            v[i][j]  = v[i][j] + v[i+1][j] +v[i][j+1]-v[i+1][j+1];
            
        }
    }
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //cout<<v[i][j] <<" ";
        }
    }
    
    int ans = INT_MIN;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            ans = max(ans,v[i][j]);
        }
    }
    return ans;
    
}
