#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c[10000];
    int i = 0, len = 0;
    while (gets(c))
    {
        len = strlen (c);
        for(i=0; i<len; i++)
        {
            if(c[i] == 'q' || c[i] == 'Q')
                printf("{");
            else if(c[i] == 'w' || c[i] == 'W')
                printf("}");
            else if(c[i] == 'e' || c[i] == 'E')
                printf("q");
            else if(c[i] == 'r' || c[i] == 'R')
                printf("w");
            else if(c[i] == 't' || c[i] == 'T')
                printf("e");
            else if(c[i] == 'y' || c[i] == 'Y')
                printf("r");
            else if(c[i] == 'u' || c[i] == 'U')
                printf("t");
            else if(c[i] == 'i' || c[i] == 'I')
                printf("y");
            else if(c[i] == 'o' || c[i] == 'O')
                printf("u");
            else if(c[i] == 'p' || c[i] == 'P')
                printf("i");
            else if(c[i] == '{' || c[i] == '[')
                printf("o");
            else if(c[i] == '}' || c[i] == ']')
                printf("p");
            else if(c[i] == 'a' || c[i] == 'A')
                printf(";");
            else if(c[i] == 's' || c[i] == 'S')
                printf("'");
            else if(c[i] == 'd' || c[i] == 'D')
                printf("a");
            else if(c[i] == 'f' || c[i] == 'F')
                printf("s");
            else if(c[i] == 'g' || c[i] == 'G')
                printf("d");
            else if(c[i] == 'h' || c[i] == 'H')
                printf("f");
            else if(c[i] == 'j' || c[i] == 'J')
                printf("g");
            else if(c[i] == 'k' || c[i] == 'K')
                printf("h");
            else if(c[i] == 'l' || c[i] == 'L')
                printf("j");
            else if(c[i] == ';' || c[i] == ':')
                printf("k");
            else if(c[i] == 39 || c[i] == '"')
                printf("l");
            else if(c[i] == 'z' || c[i] == 'Z')
                printf(".");
            else if(c[i] == 'x' || c[i] == 'X')
                printf("/");
            else if(c[i] == 'c' || c[i] == 'C')
                printf("z");
            else if(c[i] == 'v' || c[i] == 'V')
                printf("x");
            else if(c[i] == 'b' || c[i] == 'B')
                printf("c");
            else if(c[i] == 'n' || c[i] == 'N')
                printf("v");
            else if(c[i] == 'm' || c[i] == 'M')
                printf("b");
            else if(c[i] == ',' || c[i] == '<')
                printf("n");
            else if(c[i] == '.' || c[i] == '>')
                printf("m");
            else if(c[i] == '/' || c[i] == '?')
                printf(",");
            else
                printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}
