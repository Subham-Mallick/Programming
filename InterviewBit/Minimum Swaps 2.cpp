int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    pair<int,int> v[n];
    
    for(int i=0;i<n;i++)
    {
        v[i].first = A[i];
        v[i].second = i;
    }
    
    sort(v,v+n);
    
    vector<int> vis(n,0);
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        if( vis[i] || v[i].second == i )
        continue;
        
        int j=i;
        int cycle = 0;
        while(vis[j]==0)
        {
            vis[j] = 1;
            j = v[j].second;
            
            cycle++;
            
        }
        if(cycle)
            ans+=(cycle-1);
    }
    
    return ans;
    
    
}
