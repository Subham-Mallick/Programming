vector<int> func( vector<int> v,int r )
{
    
    r = r % v.size();
    reverse(v.begin(),v.begin()+r);
    reverse(v.begin()+r,v.end());
    reverse(v.begin(),v.end());
    
    return v;
}

vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int> > ans;
    for(int i=0;i<B.size();i++)
    {
        vector<int> v = A;
        ans.push_back(func(v,B[i]));
    }
    return ans;
    
}
