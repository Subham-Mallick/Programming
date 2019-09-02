void rightShift(vector<int> &v, int s,int e)
{
    reverse(v.begin()+s,v.begin()+e+1);
    reverse(v.begin()+s+1,v.begin()+e+1);
}

vector<int> Solution::solve(vector<int> &A) {
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<0 and i%2==1)
        {
            int j;
            for(j=i+1;j<A.size();j++)
            {
                if(A[j]>=0)
                break;
            }
            if(j!=A.size())
            {
                rightShift(A,i,j);
            }
        }
        else if(A[i]>=0 and i%2==0)
        {
            int j;
            for(j=i+1;j<A.size();j++)
            {
                if(A[j]<0)
                break;
            }
            if(j!=A.size())
            {
                rightShift(A,i,j);
            }
        }
        
    }
    return A;
    
}
