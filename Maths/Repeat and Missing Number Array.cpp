
/*
You are given a read only array of n integers from 1 to n.  Each integer appears exactly once except A which appears twice and B which is missing. Return A and B.  Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Note that in your output A should precede B.  Example:
Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long sum=0;
    long long sqSum=0;
    long long n = A.size();
    
    for(int i=0;i<A.size();i++)
    {
        sum+=(long long)A[i];
        sqSum +=(long long)A[i]*(long long)A[i];
        

    }

    long long diff = (n*(n+1)/2)-sum;
    
    long long diff2 = ((n*(n+1)*(2*n+1))/6)-sqSum;
    
    long long sum_ = diff2/diff;
    
    int req = (sum_-diff)/2;
    int mis = (sum_+diff)/2;
    vector<int> ans;
    ans.push_back(req);
    ans.push_back(mis);
    
    return ans;
    
    // return { (int)(sum_-diff)/2 , (int)(sum_+diff)/2    }
    

    
}
