#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    int ck;
    char Inpch, save;
    while(1)
    {
        ck = sf("%c", &Inpch);
        if(ck != 1) return 0;
        if(Inpch == 'a' || Inpch == 'A' || Inpch == 'e' || Inpch == 'E' || Inpch == 'i' || Inpch == 'I' || Inpch == 'o' || Inpch == 'O' || Inpch == 'u' || Inpch == 'U')
        {
            pf("%c", Inpch);
            while(1)
            {
                sf("%c", &Inpch);
                if(!isalpha(Inpch))
                    break;
                pf("%c", Inpch);
            }
            pf("ay%c", Inpch);
        }
        else if(isalpha(Inpch))
        {
            save = Inpch;
            while(1)
            {
                sf("%c", &Inpch);
                if(!isalpha(Inpch))
                    break;
                pf("%c", Inpch);
            }
            pf("%cay%c", save, Inpch);
        }
        else
            pf("%c", Inpch);
    }
    return 0;
}
