#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<Windows.h>
#include<ctime>



void print_book(char** book, size_t N) {     // ф-и€, вывод списка на экран
    std::cout << "No\tName\t" << std::endl;  // шапка книга
    for (size_t i = 0; i < N; i++)
    {
        std::cout << (i + 1) << '\t';        // номер по пор€дку

        if (book[i] == NULL) {               // если нет данных 
            std::cout << "--\t\t";           //  - то выводить на экран "--"
        }
        else {                               // если есть данные    
            std::cout << book[i] << '\t';   
        }
        std::cout << std::endl;
    }
}

bool add_name(char** book, size_t N, const char* name) {  // ф-и€, заполнение списка
    if (name == NULL) {
        std::cout << "NULL-argument in add_name()" << std::endl;
    }
    size_t i = 0;                          // находим 1ую пустую €чейку и в нее заполн€ем
    while (i < N && book[i] != NULL) {
        ++i;
    }
    if (i == N) {                          // i == N - список заполнен (нет пустых)
        return false;
    }
    book[i] = new char[strlen(name) + 1];  // выдел€ем пам€ть дл€ имени
    strcpy(book[i], name);                 // копируем строку в book из name

    return true;
}

bool input_name(char** book, size_t N) {  // ф-и€, ввод данных пользователем
    const size_t BUF_SIZE = 50;           // буфер дл€ данных имени
    char* name = new char[BUF_SIZE];      // выдел€ем пам€ть дл€ имени
    std::cout << "Enter student`s name: ";
    std::cin.getline(name, BUF_SIZE);     // ввод пользователем имени
    bool res = add_name(book, N, name);

    delete[] name;
    return res;
}

void sort_name(char** book, size_t N) {     // ф-и€, сортировка по имени
    bool need_restart;
    do {                                    // цикл попарной перестановки, повтор€ем пока это нужно
        need_restart = false;
        for (size_t i = 0; i < N - 1; i++)  // цикл по строкам списка
        {
            if (book[i] != NULL && book[i + 1] != NULL) {  // проверка, что €чейки заполнены
                if (strcmp(book[i], book[i + 1]) == 1) {   // если phonebook[i][0] > phonebook[i + 1][0])
                    char* tmp_ptr = book[i];               // пор€док неправильный
                    book[i + 1] = tmp_ptr;                 // нужно переставить €чейки [i] и [i+1]
                    book[i] = book[i + 1];     

                    need_restart = true;
                }
            }
        }

    } while (need_restart);
    print_book(book, N);
}