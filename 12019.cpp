#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char week[7][10]= {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int doomsday[13]={0,3,28,7,4,9,6,11,8,5,10,7,12};
    int data, tmp;
    scanf("%d",&data);
    while(data--)
    {
        int day,m,d;
        scanf("%d %d",&m,&d);
        day = d - doomsday[m];

        tmp = day / 7;
        tmp *= 7;
        day -= tmp;

        if( day >= 0 )
            puts(week[day]);
        else
            puts(week[7+day]);
    }
    return 0;
}

