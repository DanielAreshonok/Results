//структуры
#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct time
{
    int min;
    int sec;
    int milsec;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct results
{
    int number;
    person competitor;
    time start;
    time finish;
    char club[MAX_STRING_SIZE];
};

#endif
