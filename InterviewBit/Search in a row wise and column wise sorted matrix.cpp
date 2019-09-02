int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
     int m = A[0].size();
    int i=0,j=m-1;
    while(i<n and j>=0)
    {
        if(B==A[i][j])
        {
            return ((i+1)*1009) + (j+1);
        }
        if(B < A[i][j])
        {
            j--;
        }
        else 
            i++;
    }
    return -1;
    
}
