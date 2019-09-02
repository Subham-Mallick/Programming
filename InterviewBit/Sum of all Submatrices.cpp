int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int sum = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            sum += (A[i][j] * (i+1) * (j+1) * (n-i) * (n-j)); 
        }
    return sum;
}
