int return_week_day(int y,int m,int d)
{
    int w;
    if(m==1 || m==2) 
    {   
        m+=12; 
        y--;
    } 
    w=(d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return w;
}