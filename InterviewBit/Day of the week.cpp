

string Solution::solve(int A, int B, int C) {
    
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if(B<3)
        C = C-1;
    
    int p = (  C + C/4 - C/100 + C/400 + t[B-1] + A  )%7;
    switch(p)
    {
        case 0:
            return "sunday";
            break;
        case 1:
            return "monday";
            break;
        case 2:
            return "tuesday";
            break;
        case 3:
            return "wednesday";
            break;
        case 4:
            return "thursday";
            break;
        case 5:
            return "friday";
            break;
        case 6:
            return "saturday";
            break;
    }
    
}

