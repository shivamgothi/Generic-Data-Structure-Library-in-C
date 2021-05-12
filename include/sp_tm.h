#ifndef __SP_TM__H
#define __SP_TM__H 123
typedef struct __$_date
{
int day;
int month;
int year;
int hour;
int minutes;
int seconds;
int weekDay;
}Date; 
Date now();
void dateToString(char *s,char *t,Date d);
int day(Date d);
int month(Date d);
int year(Date d);
int dayOfWeek(Date d);
int hours(Date d);
int minutes(Date d);
int seconds(Date d);
void monthName(char *m,Date d);
void dayName(char *m,Date d);
Date addDay(Date d,int x);
int isLeapYear(int y);
#endif



