#include "Stamp.h"
#include <stdio.h>

Stamp::Stamp(time_t stamp)
{
    //cto
    //stamp+=3600*24;
    time_t t;
    second = (int)(stamp % 60);//0-59
    t = (stamp - second) / 60;
    minute =(int)(t % 60);// 0-59
    t = (t - minute) / 60;//
    hour = (int)(t % 24);//0-23
    day = (int)((t - hour) / 24);//1
    //day =+ 1;
    int temp = 0;
    int ytemp = 1970;

    while(temp <= day)
    {
        ytemp+=1;
        temp+=dayYearHas(ytemp);
    }

    temp -= dayYearHas(ytemp);

    year = ytemp - 1;//

    int em = 1;
    while(temp <= day)
    {
        temp+=dayMonthHas(year, em);
        em += 1;
    }
    temp -= dayMonthHas(year, em-1);

    month = em - 1;//

    int days = 0;

    while(temp != day)
    {
        temp+=1;
        days++;
    }

    day = days +1;//


}

Stamp::~Stamp()
{
    //dtor
}

bool Stamp::isLeapYear(int y)
{
    if(y % 400 == 0)
        return true;
    if(y % 4 == 0 && y % 100 != 0)
        return true;
    return false;
}

int Stamp::dayYearHas(int ytemp)
{
    if(isLeapYear(ytemp))
        return 366;
    else
        return 365;
}
int Stamp::dayMonthHas(int y, int mon)
{
    int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mon == 2 && isLeapYear(y))
    {
        return 29;
    }
    return a[mon - 1];
}

string Stamp::getTime()
{
    char buff[40]={0};
    char s[13][4] = {"000","JAN", "FEB", "MAR","APR", "MAY", "JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    sprintf(buff, "%s %d, %d %02d:%02d:%02d", s[month],day, year, hour,minute, second);
    string time = buff;
    return time;
}
//int Stamp::getYear();
//int Stamp::getMonth();
//int Stamp::getDay();
//int Stamp::getHour();
//int Stamp::getMinute();
//int Stamp::getSecond();
