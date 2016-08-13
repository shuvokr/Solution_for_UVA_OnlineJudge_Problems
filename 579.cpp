#include<stdio.h>
int main()
{
    int h,m;
    while(scanf("%d:%d",&h,&m)==2)
    {
        if(h==0 && m==0)break;
        float a;
        a=((h*60)*0.5)+(m*0.5)-(m*6);
        if(a<0)a*=-1;
        if(a>180.000)a=360.000-a;
        printf("%.3f\n",a);
    }
    return 0;
}
