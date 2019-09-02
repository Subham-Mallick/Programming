void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int row = A.size();
    int col = A[0].size();
    
    int rowF = 0;
    int colF = 0;
    
    for(int i=0;i<col;i++)
    {
        if(A[0][i]==0)
        {
            rowF = 1;
            break;
        }
    }
    
    for(int i=0;i<row;i++)
    {
        if(A[i][0]==0)
        {
            colF = 1;
            break;
        }
    }
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            
            if(A[i][j]==0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            if( A[0][j] ==0 or A[i][0]==0 )
            {
                A[i][j] = 0;
            }
        }
    }
    
    if(rowF==1){
        for(int i=0;i<col;i++)
         A[0][i]=0;
    }    
    if(colF==1){
        for(int i=0;i<row;i++)
         A[i][0]=0;
    }

    
}
