int Solution::maxSubArray(const vector<int> &A) {

    int maxSoFar = A[0];
    int currMax = A[0];
    
    for(int i=1;i<A.size();i++)
    {
        
        currMax = max(A[i],currMax+A[i]);
        maxSoFar = max(currMax,maxSoFar);
        
    }
    return maxSoFar;
    
}
