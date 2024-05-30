#include <iostream>
#include <iomanip>
#include "marathon.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;
void filter_time(_time* mar_time, m_result* _results[], int& size)
{
    cout << "Игроки с временем < 2:50:00:" << endl;
    for (int i = 0; i < size; i++)
    {
        if (_results[i]->finish.t_count() - _results[i]->start.t_count() < mar_time->t_count()) {
            /********** вывод номера **********/
            cout << "Номер игрока........: ";
            cout << _results[i]->number << " ";
            /********** вывод игрока **********/
            cout << "Игрок........: ";
            // вывод фамилии
            cout << _results[i]->competitor.last_name << " ";
            // вывод первой буквы имени
            cout << _results[i]->competitor.first_name[0] << ". ";
            // вывод первой буквы отчества
            cout << _results[i]->competitor.middle_name[0] << ".";
            cout << '\n';
            /********** вывод начала **********/
                               // вывод минут
            cout << "Дата выдачи.....: ";
            cout << setw(2) << setfill('0') << _results[i]->start.min << ':';
            // вывод секунд
            cout << setw(2) << setfill('0') << _results[i]->start.sec << ':';
            // вывод милисекунд
            cout << setw(2) << setfill('0') << _results[i]->start.milsec;
            cout << '\n';
            /********** вывод клуба **********/
            cout << "Спортивный клуб...........: ";
            // вывод клуба
            cout << '"' << _results[i]->club << '"';
            cout << '\n';
            cout << '\n';
        }
    }
}
void filter_name(const char* club_name, m_result* _results[], int& size)
{
    cout << "Игроки команды " << club_name << ":" << endl;
    for (int i = 0; i < size; i++)
    {
        if (_results[i]->club == club_name) {
            /********** вывод номера **********/
            cout << "Номер игрока........: ";
            cout << _results[i]->number << " ";
            /********** вывод игрока **********/
            cout << "Игрок........: ";
            // вывод фамилии
            cout << _results[i]->competitor.last_name << " ";
            // вывод первой буквы имени
            cout << _results[i]->competitor.first_name[0] << ". ";
            // вывод первой буквы отчества
            cout << _results[i]->competitor.middle_name[0] << ".";
            cout << '\n';
            /********** вывод начала **********/
            // вывод минут
            cout << "Дата выдачи.....: ";
            cout << setw(2) << setfill('0') << _results[i]->start.min << ':';
            // вывод секунд
            cout << setw(2) << setfill('0') << _results[i]->start.sec << ':';
            // вывод милисекунд
            cout << setw(2) << setfill('0') << _results[i]->start.milsec;
            cout << '\n';
            /********** вывод клуба **********/
            cout << "Спортивный клуб...........: ";
            // вывод клуба
            cout << '"' << _results[i]->club << '"';
            cout << '\n';
            cout << '\n';
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №10. GIT\n";
    cout << "Вариант №1. Результаты марафона\n";
    cout << "Автор: Даниил Арешонок\n\n";
    m_result* _results[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", _results, size);
        cout << "***** результаты марафона *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод номера **********/
            cout << "Номер игрока........: ";
            cout << _results[i]->number << " ";
            /********** вывод игрока **********/
            cout << "Игрок........: ";
            // вывод фамилии
            cout << _results[i]->competitor.last_name << " ";
            // вывод первой буквы имени
            cout << _results[i]->competitor.first_name[0] << ". ";
            // вывод первой буквы отчества
            cout << _results[i]->competitor.middle_name[0] << ".";
            cout << '\n';
            /********** вывод начала **********/
                        // вывод минут
                        cout << "Дата выдачи.....: ";
                        cout << setw(2) << setfill('0') << _results[i]->start.min << ':';
                        // вывод секунд
                        cout << setw(2) << setfill('0') << _results[i]->start.sec << ':';
                        // вывод милисекунд
                        cout << setw(2) << setfill('0') << _results[i]->start.milsec;
                        cout << '\n';
                        /********** вывод клуба **********/
                        cout << "Спортивный клуб...........: ";
                        // вывод клуба
                        cout << '"' << _results[i]->club << '"';
                        cout << '\n';
                        cout << '\n';
                    }
                    filter_name("Спартак", _results, size);
                    _time* temp = new _time(2, 50, 00);
                    filter_time(temp, _results, size);
                    for (int i = 0; i < size; i++)
                    {
                        delete _results[i];
                    }
                    delete temp;
                }
                catch (const char* error)
                {
                    cout << error << '\n';
                }
                return 0;
            }
