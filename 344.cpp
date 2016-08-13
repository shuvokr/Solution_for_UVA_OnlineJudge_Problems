#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    char ch[120][10]={"i","ii","iii","iv","v","vi","vii","viii","ix","x","xi","xii","xiii","xiv","xv","xvi","xvii","xviii","xix","xx","xxi","xxii","xxiii","xxiv","xxv","xxvi","xxvii","xxviii","xxix","xxx","xxxi","xxxii","xxxiii","xxxiv","xxxv","xxxvi","xxxvii","xxxviii","xxxix","xl","xli","xlii","xliii","xliv","xlv","xlvi","xlvii","xlviii","xlix","l","li","lii","liii","liv","lv","lvi","lvii","lviii","lix","lx","lxi","lxii","lxiii","lxiv","lxv","lxvi","lxvii","lxviii","lxix","lxx","lxxi","lxxii","lxxiii","lxxiv","lxxv","lxxvi","lxxvii","lxxviii","lxxix","lxxx","lxxxi","lxxxii","lxxxiii","lxxxiv","lxxxv","lxxxvi","lxxxvii","lxxxviii","lxxxix","xc","xci","xcii","xciii","xciv","xcv","xcvi","xcvii","xcviii","xcix","c"};
    int m, n, i, v, x, l, c, number, len = 0;
    while(sf("%d", &number) != 0 )
    {
        if(number == 0) return 0;
        i = 0; v = 0; x = 0; l = 0; c = 0;
        for(m = 0; m < number; m++)
            for(n = 0; n < strlen(ch[m]); n++)
            {
                if(ch[m][n] == 'i') i++;
                else if(ch[m][n] == 'v') v++;
                else if(ch[m][n] == 'x') x++;
                else if(ch[m][n] == 'l') l++;
                else if(ch[m][n] == 'c') c++;
            }
        pf("%d: %d i, %d v, %d x, %d l, %d c\n",number,i,v,x,l,c);
    }
}
