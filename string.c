#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[50], pat[50], rep[50];
int start = 0, patfound = 0;
int lasts, lastp, lastr;
void replacepattern()
{
 int i, j;
 lastr = strlen(rep)-2;
 
 if(lastp != lastr)
 {
 printf("\nInvalid length of replace string");
 exit(0);
 }
 else
 {
 i = start;
 for(j=0; j<=lastr; j++)
 {
 str[i] = rep[j];
 i++;
 }
 }
 return;
}
void findpattern()
{
 int i, j, inmatch;
 lasts = (strlen(str))-2;
 lastp = (strlen(pat))-2;
 int endmatch;
 for(endmatch = lastp; endmatch<=lasts; endmatch++, start++)
 {
 if(str[endmatch] == pat[lastp])
 {
 inmatch = start;
 j=0;
 while(j<lastp)
 {
 if(str[inmatch] == pat[j])
 {
 inmatch++;
 j++;
 }
 else
 {
 break;
 }
 }
 if(j == lastp)
 {
 patfound = 1;
 replacepattern();
 }
 }
 }
 return;
}
void main()
{
 printf("\nEnter the main string(STR): ");
 fgets(str, 50, stdin);
 printf("\nEnter the pattern to be matched(PAT): ");
 fgets(pat, 50, stdin);
 printf("\nEnter the string to be replaced(REP): ");
 fgets(rep, 50, stdin);
 printf("\nThe string before pattern match is: %s", str);
 findpattern();
 if(patfound == 0)
 printf("\nThe pattern is not found in the main string");
 else
 printf("\nThe string after pattern match and replace is: %s ",str);
 return;
}
