#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

int a[31][31];
int n,ai,aj,bi,bj;

void _rs()
{
 ai = bi = aj = bj = -1;
    for(int i = 0; i < n; i++ )
 {
        a[i][0] = i;
        a[i][1] = -1;
    }
}
void _find(int s, int e)
{
    for(int i = 0; i < n; i++ )
 {
        for(int j = 0; a[i][j] != -1; j++ )
  {
            if (a[i][j] == s )
   {
                ai = i;
                aj = j;
            }

            else if ( a[i][j] == e )
   {
                bi = i;
                bj = j;
            }
        }
    }
}

bool _check(int s, int e)
{
    if ( s == e )
     return false;
    for ( int i = 0; i < n; i++ )
 {
        for ( int j = 0; a[i][j] != -1; j++ )
  {
            if ( s == a[i][j] )
   {
                for(int k = 0; a[i][k] != -1; k++ )
    {
                    if ( e == a[i][k] )
                        return false;
                }
            }
        }
    }
    return true;
}
void moveOnto(int s, int e)
{
    if ( !_check(s, e) )
     return;
    _find (s, e);

    for ( int j = aj + 1;a[ai][j] != -1;j++ )
 {
        a[a[ai][j]][0] = a[ai][j];
        a[a[ai][j]][1] = -1;
    }

    a[ai][aj] = -1;
    for( int j = bj+1; a[bi][j] != -1; j++ )
 {
        a[a[bi][j]][0] = a[bi][j];
        a[a[bi][j]][1] = -1;
    }

    a [bi][bj + 1] = s;
    a [bi][bj + 2] = -1;

}

void moveOver(int s, int e)
{
    if ( !_check(s,e))
     return;
    _find(s, e);
    for(int j = aj+1; a[ai][j] != -1; j++ )
 {
        a [a[ai][j]][0] = a[ai][j];
        a [a[ai][j]][1] = -1;
    }
    a [ai][aj] = -1;
    bj++;
    while(a[bi][bj] != -1 )
        bj++;
    a[bi][bj] = s;
    a[bi][++bj] = -1;
}

void pileOnto(int s, int e)
{
    if ( !_check(s,e))
     return;
    _find(s,e);
    for(int j = bj + 1; a[bi][j] != -1; j++)
 {
        a[a[bi][j]][0] = a[bi][j];
        a[a[bi][j]][1] = -1;
    }
    for(int j = aj; a[ai][j] != -1; j++ )
        a[bi][++bj] = a[ai][j];
    a[bi][bj+1] = -1;
    a[ai][aj] = -1;
}

void pileOver(int s, int e)
{
    if ( !_check(s,e))
     return;
    _find(s,e);
    bj++;
    while (a[bi][bj] != -1 )
        bj++;
    for(int j = aj; a[ai][j] != -1; j++ )
        a [bi] [bj++] = a[ai][j];
    a [bi][bj] = -1;
    a [ai][aj] = -1;
}
///////////////////////////
void input()
{
 scanf("%d",&n);
 _rs();
 char cmd[10],act[10];
 int s,e;
 while(true)
 {
  memset(cmd,0,10);
  memset(act,0,10);
  scanf("%s",&cmd);
  if(cmd[0]=='q')
   break;
  scanf("%d %s %d",&s,&act,&e);
        if(strcmp(cmd,"move")==0 && strcmp(act,"onto")==0 )
  {
            moveOnto(s,e);
        }
        else if(strcmp(cmd,"move")==0 && strcmp(act,"over")==0 )
  {
            moveOver(s,e);
        }
        else if(strcmp(cmd,"pile")==0 && strcmp(act,"onto")==0 )
  {
            pileOnto(s,e);
        }
        else if(strcmp(cmd,"pile")==0 && strcmp(act,"over")==0 ) {
            pileOver(s,e);
        }
 }
}

void output()
{
    for ( int i = 0; i < n; i++ ) {
        printf ("%d:", i);
        for ( int j = 0; a [i] [j] != -1; j++ )
            printf (" %d", a [i] [j]);
        printf ("\n");
    }
}
int main()
{
  input();
  output();

 return 0;
}
