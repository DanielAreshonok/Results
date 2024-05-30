#include "file_reader.h"
#include "constants.h"
#include "marathon.h"

#include <fstream>
#include <cstring>
using namespace std;

_time convert(char* str)
{
    _time result;
    char* context = NULL;
    char* str_number = strtok_r(str, ":", &context);
    result.min = atoi(str_number);
    str_number = strtok_r(NULL, ":", &context);
    result.sec = atoi(str_number);
    str_number = strtok_r(NULL, ":", &context);
    result.milsec = atoi(str_number);
    return result;
}

void read(const char* file_name, m_result* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            m_result* item = new m_result;
            file >> item->number;
            file >> item->competitor.last_name;
            file >> item->competitor.first_name;
            file >> item->competitor.middle_name;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
           file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->club, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
