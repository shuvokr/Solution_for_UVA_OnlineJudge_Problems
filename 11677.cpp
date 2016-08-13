#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour1, hour2, minute1, minute2, time_sleep, time_start, time_end;

    while(scanf("%d %d %d %d", &hour1, &minute1, &hour2, &minute2)==4)
    {
        if(hour1==0 && minute1==0 && hour2==0 && minute2==0)
            return 0;

        time_start=((hour1*60)+minute1);
        time_end=((hour2*60)+minute2);
        time_sleep=abs(time_end-time_start);

        if(time_start>time_end)
        {
            time_sleep=1440-time_sleep;
        }
        else if(time_start==time_end)
        {
            time_sleep=1440;
        }
        printf("%d\n", time_sleep);
    }
    return 0;
}
