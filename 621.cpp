    #include <stdio.h>
    #include <string.h>

    int TC;
    char s[1000000];

    int main ()
    {
       scanf ("%d", &TC);
       getchar();
       while (TC --)
       {
          gets (s);
          int le = strlen(s);
          if ((s[0] == '1' || s[0] == '4' || (s[0] == '7' && s[1]=='8'))&& le<=2)
             printf ("+\n");
          else
          {
             if (le > 1 && s[le - 1] == '5' && s[le - 2] == '3')
                printf ("-\n");
             else if (le > 1 && s[0] == '9' && s[le - 1] == '4')
                printf ("*\n");
             else if (le > 2 && s[0] == '1' && s[1] == '9' && s[2] == '0')
                printf ("?\n");
          }
       }

       return 0;
    }
