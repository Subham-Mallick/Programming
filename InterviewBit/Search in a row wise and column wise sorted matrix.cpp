int Solution::solve(vector<vector<int> > &A, int B) {
    
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0] <= B )
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j] == B)
                return (i+1)*1009 + (j+1);
            }
        }
    }
    return -1;
}
