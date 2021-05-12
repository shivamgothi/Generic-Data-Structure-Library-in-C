#ifndef __SP_TM__C
#define __SP_TM__C 123
#include<sp_tm.h>
#include<time.h>
Date now()
{
Date d;
time_t n;
struct tm *t;
time(&n);
t=localtime(&n);
d.sp_day=t->tm_mday;
d.sp_month=t->tm_mon+1;
d.sp_year=t->tm_year+1900;
d.sp_hour=t->tm_hour;
d.sp_minutes=t->tm_min;
d.sp_seconds=t->tm_sec;
d.sp_weekDay=t->tm_wday+1;
return d;
}
void dateToString(char *s,char *t,Date d)
{

while(*t)
{
if(*t=='d')
{
if(d.sp_day>9)
{
*s=d.sp_day/10;
s++;
t++;
*s=d.sp_day%10;
s++;
t++;
}
else
{
*s=0;
s++;
t++;
*s=d.sp_day;
s++;
t++;
}
*s=*t;
t++;
s++;
}
if(*t=='M')
{
if(d.sp_month>9)
{
*s=d.sp_month/10;
s++;
t++;
*s=d.sp_month%10;
s++;
t++;
}
else
{
*s=0;
s++;
t++;
*s=d.sp_month;
s++;
t++;
}
*s=*t;
t++;
s++;
}
if(*t=='y')
{
j=1000;
num=d.sp_year;
while(j>0)
{
*s=num/j;
num=num-((*s)*j);
s++;
t++;
j=j/10;
}
*s=*t;
s++;
t++;
}
if(*t=='h')
{
if(d.sp_hours>9)
{
*s=d.sp_hours/10;
s++;
t++;
*s=d.sp_hours%10;
s++;
t++;
}
else
{
*s=0;
s++;
t++;
*s=d.sp_hours;
s++;
t++;
}
*s=*t;
t++;
s++;
}
if(*t=='m')
{
if(d.sp_minutes>9)
{
*s=d.sp_minutes/10;
s++;
t++;
*s=d.sp_minutes%10;
s++;
t++;
}
else
{
*s=0;
s++;
t++;
*s=d.sp_minutes;
s++;
t++;
}
*s=*t;
t++;
s++;
}
if(*t=='s')
{
if(d.sp_seconds>9)
{
*s=d.sp_seconds/10;
s++;
t++;
*s=d.sp_seconds%10;
s++;
t++;
}
else
{
*s=0;
s++;
t++;
*s=d.sp_seconds;
s++;
t++;
}
*s=*t;
t++;
s++;
}
}
int day(Date d)
{
return d.sp_day;
}
int month(Date d)
{
return d.sp_month;
}
int year(Date d)
{
return d.sp_year;
}
int dayOfWeek(Date d)
{
return sp_weekDay; 
}
int hours(Date d)
{
return d.sp_hours;
}
int minutes(Date d)
{
return d.sp_minutes;
}
int seconds(Date d)
{
return d.sp_seconds;
}
#endif




