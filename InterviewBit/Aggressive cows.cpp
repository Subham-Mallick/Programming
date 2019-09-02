bool check(vector<int> A,int mid,int cow)
{
    int c=1;
    int pos = A[0];
    for(int i=1;i<A.size();i++)
    {
        if(A[i]-pos >= mid)
        {
            pos = A[i];
            c++;
            if(c==cow)
                return true;
        }
    }
    return false;
}

int binary(vector<int> A,int cow,int ans)
{
    int low = 1,high = A[A.size()-1]-A[0]+1;
    
    while(low<high)
    {
        int mid = low + (high-low)/2;
        //cout<<low<<" "<<high<<"@";
        if(check(A,mid,cow))
        {
            if(mid>ans)
                ans=mid;
            low=mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return ans;
    
}

int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    return binary(A,B,INT_MIN);
    
    
    
    
}
