#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<Windows.h>
#include<ctime>



void print_book(char** book, size_t N) {     // �-��, ����� ������ �� �����
    std::cout << "No\tName\t" << std::endl;  // ����� �����
    for (size_t i = 0; i < N; i++)
    {
        std::cout << (i + 1) << '\t';        // ����� �� �������

        if (book[i] == NULL) {               // ���� ��� ������ 
            std::cout << "--\t\t";           //  - �� �������� �� ����� "--"
        }
        else {                               // ���� ���� ������    
            std::cout << book[i] << '\t';   
        }
        std::cout << std::endl;
    }
}

bool add_name(char** book, size_t N, const char* name) {  // �-��, ���������� ������
    if (name == NULL) {
        std::cout << "NULL-argument in add_name()" << std::endl;
    }
    size_t i = 0;                          // ������� 1�� ������ ������ � � ��� ���������
    while (i < N && book[i] != NULL) {
        ++i;
    }
    if (i == N) {                          // i == N - ������ �������� (��� ������)
        return false;
    }
    book[i] = new char[strlen(name) + 1];  // �������� ������ ��� �����
    strcpy(book[i], name);                 // �������� ������ � book �� name

    return true;
}

bool input_name(char** book, size_t N) {  // �-��, ���� ������ �������������
    const size_t BUF_SIZE = 50;           // ����� ��� ������ �����
    char* name = new char[BUF_SIZE];      // �������� ������ ��� �����
    std::cout << "Enter student`s name: ";
    std::cin.getline(name, BUF_SIZE);     // ���� ������������� �����
    bool res = add_name(book, N, name);

    delete[] name;
    return res;
}

void sort_name(char** book, size_t N) {     // �-��, ���������� �� �����
    bool need_restart;
    do {                                    // ���� �������� ������������, ��������� ���� ��� �����
        need_restart = false;
        for (size_t i = 0; i < N - 1; i++)  // ���� �� ������� ������
        {
            if (book[i] != NULL && book[i + 1] != NULL) {  // ��������, ��� ������ ���������
                if (strcmp(book[i], book[i + 1]) == 1) {   // ���� phonebook[i][0] > phonebook[i + 1][0])
                    char* tmp_ptr = book[i];               // ������� ������������
                    book[i + 1] = tmp_ptr;                 // ����� ����������� ������ [i] � [i+1]
                    book[i] = book[i + 1];     

                    need_restart = true;
                }
            }
        }

    } while (need_restart);
    print_book(book, N);
}