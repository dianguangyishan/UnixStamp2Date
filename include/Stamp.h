#ifndef STAMP_H
#define STAMP_H
#include <string>
#include <iostream>
using namespace std;


class Stamp
{
    public:
        Stamp(time_t stamp);
        virtual ~Stamp();
        string getTime();
//        int getYear();
//        int getMonth();
//        int getDay();
//        int getHour();
//        int getMinute();
//        int getSecond();

        bool isLeapYear(int y);

        int dayYearHas(int y);
        int dayMonthHas(int y, int mon);

    protected:
    public:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
};

#endif // STAMP_H
