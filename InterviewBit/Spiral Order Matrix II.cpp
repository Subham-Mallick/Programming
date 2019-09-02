vector<vector<int> > Solution::generateMatrix(int n) {
    
    if (n<=0)
    return vector< vector<int> >();
    
    vector< vector<int> > ans (n,vector<int>(n));
    
    int rowS = 0;
    int rowE = n-1;
    
    int colS = 0;
    int colE = n-1;
    
    int ele = 1;
    
    while(true)
    {
        if(ele > n*n) break;
        
        for(int i=colS;i<=colE;i++)
        {
            ans[rowS][i] = ele++;
        }
        rowS++;
        
        for(int i=rowS;i<=rowE;i++)
        {
            ans[i][colE] = ele ++;
        }
        colE--;
        
        for(int i=colE;i>=colS;i--)
        {
            ans[rowE][i] = ele++;
        }
        rowE --;
        
        for(int i=rowE;i>=rowS;i--)
        {
            ans[i][colS] = ele++;
        }
        colS++;
        
        
    }
    return ans;
    
}
vector<vector<int> > Solution::generateMatrix(int n) {
    
    if (n<=0)
    return vector< vector<int> >();
    
    vector< vector<int> > ans (n,vector<int>(n));
    
    int rowS = 0;
    int rowE = n-1;
    
    int colS = 0;
    int colE = n-1;
    
    int ele = 1;
    
    while(true)
    {
        if(ele > n*n) break;
        
        for(int i=colS;i<=colE;i++)
        {
            ans[rowS][i] = ele++;
        }
        rowS++;
        
        for(int i=rowS;i<=rowE;i++)
        {
            ans[i][colE] = ele ++;
        }
        colE--;
        
        for(int i=colE;i>=colS;i--)
        {
            ans[rowE][i] = ele++;
        }
        rowE --;
        
        for(int i=rowE;i>=rowS;i--)
        {
            ans[i][colS] = ele++;
        }
        colS++;
        
        
    }
    return ans;
    
}
