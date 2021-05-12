#ifndef __SP_TM__C
#define __SP_TM__C 123
#include<sp_tm.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
Date now()
{
Date d;
time_t n;
struct tm *t;
time(&n);
t=localtime(&n);
d.day=t->tm_mday;
d.month=t->tm_mon+1;
d.year=t->tm_year+1900;
d.hour=t->tm_hour;
d.minutes=t->tm_min;
d.seconds=t->tm_sec;
d.weekDay=t->tm_wday+1;
return d;
}
void dateToString(char *s,char *t,Date d)
{
int i,num;
while(1)
{
if(*t=='d' || *t=='D')
{
num=d.day;
if(num>9)
{
*s=(num/10)+48;
s++;
t++;
*s=(num%10)+48;
s++;
t++;
}
else
{
*s=0+48;
s++;
t++;
*s=num+48;
s++;
t++;
}
*s=*t;
if(*t=='\0') break;
t++;
s++;
}
if(*t=='M' || *t=='m')
{
num=d.month;
if(num>9)
{
*s=(num/10)+48;
s++;
t++;
*s=(num%10)+48;
s++;
t++;
}
else
{
*s=0+48;
s++;
t++;
*s=num+48;
s++;
t++;
}
*s=*t;
if(*t=='\0') break;
t++;
s++;
}
if(*t=='y' || *t=='Y')
{
num=d.year;
i=3;
int j;
while(num>0)
{
j=num%10;
*(s+i)=j+48;
i--;
t++;
num=num/10;
}
s=s+4;
*s=*t;
if(*t=='\0') break;
s++;
t++;
}
if(*t=='h')
{
num=d.hour;
if(num>9)
{
*s=(num/10)+48;
s++;
t++;
*s=(num%10)+48;
s++;
t++;
}
else
{
*s=0+48;
s++;
t++;
*s=num+48;
s++;
t++;
}
*s=*t;
if(*t=='\0') break;
t++;
s++;
}
if(*t=='m')
{
num=d.minutes;
if(num>9)
{
*s=(num/10)+48;
s++;
t++;
*s=(num%10)+48;
s++;
t++;
}
else
{
*s=0+48;
s++;
t++;
*s=num+48;
s++;
t++;
}
*s=*t;
if(*t=='\0') break;
t++;
s++;
}
if(*t=='s')
{
num=d.seconds;
if(d.seconds>9)
{
*s=(num/10)+48;
s++;
t++;
*s=(num%10)+48;
s++;
t++;
}
else
{
*s=0+48;
s++;
t++;
*s=num+48;
s++;
t++;
}
*s=*t;
if(*t=='\0') break;
t++;
s++;
}
}
}
int day(Date d)
{
return d.day;
}
int month(Date d)
{
return d.month;
}
int year(Date d)
{
return d.year;
}
int dayOfWeek(Date d)
{
return d.weekDay; 
}
int hours(Date d)
{
return d.hour;
}
int minutes(Date d)
{
return d.minutes;
}
int seconds(Date d)
{
return d.seconds;
}
void monthName(char *m,Date d)
{
int num=d.month;
if(num==1) strcpy(m,"January");
else if(num==2) strcpy(m,"February");
else if(num==3) strcpy(m,"March");
else if(num==4) strcpy(m,"April");
else if(num==5) strcpy(m,"May");
else if(num==6) strcpy(m,"June");
else if(num==7) strcpy(m,"July");
else if(num==8) strcpy(m,"August");
else if(num==9) strcpy(m,"September");
else if(num==10) strcpy(m,"October");
else if(num==11) strcpy(m,"November");
else strcpy(m,"December");
}
void dayName(char *m,Date d)
{
int num=d.weekDay;
if(num==1) strcpy(m,"Sunday");
else if(num==2) strcpy(m,"Monday");
else if(num==3) strcpy(m,"Tuesday");
else if(num==4) strcpy(m,"Wednesday");
else if(num==5) strcpy(m,"Thursday");
else if(num==6) strcpy(m,"Friday");
else strcpy(m,"Saturday");
}
int isLeapYear(int y)
{
if(y%400==0 || y%4==0) return 1;
else return 0;
}
Date addDay(Date d,int n)
{
int totalDay;
Date k;
int mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int x=0,y,m,ep,z,weekDay;
int dayInYear;
int dayInMonth;
y=1901;
while(y<d.year)
{
if(isLeapYear(y)) x=x+366;
else x=x+365;
y++;
}
if(isLeapYear(y)) mth[1]=29;
ep=d.month-2;
m=0;
while(m<=ep)
{
x=x+mth[m];
m++;
}
x=x+d.day+n;
totalDay=x;
int dd;
y=1901;
while(1)
{
if(isLeapYear(y)) dayInYear=366;
else dayInYear=365;
if(x<dayInYear) break;
x=x-dayInYear;
y++;
}
if(isLeapYear(y)) mth[1]=29;
else mth[1]=28;
m=0;
while(1)
{
dayInMonth=mth[m];
if(x<dayInMonth) break;
x=x-dayInMonth;
m++;
}
m++;
k.day=x;
k.month=m;
k.year=y;
k.hour=d.hour;
k.minutes=d.minutes;
k.seconds=d.seconds;
z=totalDay%7;
weekDay=2+z;
if(weekDay>7) weekDay=weekDay%7;
k.weekDay=weekDay;
return k;
}
#endif




