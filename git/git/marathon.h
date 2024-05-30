//структуры
#ifndef MARATHON_H
#define MARATHON_H

#include "constants.h"

struct _time
{
    int min;
    int sec;
    int milsec;
    _time() {}
    _time(int t, int s, int m)
    {
        this->min = t;
        this->sec = s;
        this->milsec = m;
    }
    int t_count()
    {
        return milsec + sec * 1000 + min * 60000;
    }
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct m_result
{
    int number;
    person competitor;
    _time start;
    _time finish;
    char club[MAX_STRING_SIZE];
};

#endif
