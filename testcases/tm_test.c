#include<sp_tm.h>
#include<stdio.h>
int main()
{
char dateString[22];
char dn[16];
Date d,k;
d=now();
dateToString(dateString,"dd/mm/yyyy hh:mm:ss",d);
printf("%s\n",dateString);
printf("%d\n",d.month);
k=addDay(d,15);
dateToString(dateString,"dd/mm/yyyy hh:mm:ss",k);
printf("%s\n",dateString);
printf("%d\n",k.month);
dayName(dn,k);
printf("%s\n",dn);
return 0;
}