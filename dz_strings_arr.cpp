// dz_strings_arr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<Windows.h>
#include<ctime>


// прототипы функций для задания 1 (список студентов)
void print_book(char** book, size_t N);                     // ф-ия, вывод списка на экран
bool add_name(char** book, size_t N, const char* name);     // ф-ия, добавление имен
bool input_name(char** book, size_t N);                     // ф-ия, ввод имени пользователем
void sort_name(char** book, size_t N);                      // ф-ия, сортировка списка

// прототипы функций для задания 2 (2D массивы)
int** create_arr(size_t S, size_t S1);                      // ф-ия, создание массива
void delete_arr(int** arr, size_t S);                       // ф-ия, освобождение памяти
void fill_arr(int** arr, size_t S, size_t S1);              // ф-ия, заполнение массива
void print_arr(int** arr, size_t S, size_t S1);             // ф - ия, вывод массива на экран
int* negative(int** arr1, int** arr2, int** arr3, 
    size_t A, size_t B, size_t C, size_t D, 
    size_t E, size_t F, size_t& res_size);                  // ф-ия, отрицательные значения для массивов А В С
int* common_AC(int** arr1, int** arr3, size_t A, 
    size_t B, size_t E, size_t F, size_t& res_size);        // ф-ия, общие значения для массивов А С
int* common_ABC(int** arr1, int** arr2, int** arr3, 
    size_t A, size_t B, size_t C, size_t D, size_t E, 
    size_t F, size_t& res_size);                            // ф-ия, общие значения для массивов А В С
int* uniq_ABC(int** arr1, int** arr2, int** arr3,
    size_t A, size_t B, size_t C, size_t D, size_t E,
    size_t F, size_t& res_size);                            // ф-ия, необщие значения для массивов А В С



int main()
{
    /*   
    Написати програму, яка дає користувачеві ввести 5 прізвищ студентів, а потім сортує їх за зростанням.
    */
    size_t N = 5;  // колличество строк в списке
    char** book;   // указатель на двухмерный массив строк

    book = new char* [N];           // разименование указателя на массив и выделение памяти N
    for (size_t i = 0; i < N; i++)  // цикл по строкам
    {
        book[i] = NULL;
    }
    std::cout << "Book" << std::endl;

    char user_choice[5];                    // массив для выбора пользователя
    do {                                    // общий цикл по меню
        std::cout << "1. Show all\n"        // Меню
            << "2. Add name\n"              // Меню
            << "3. Sort by name\n"          // Меню
            << "0.Exit\n";                  // Меню
        std::cout << "Make a choice: \n";   // Меню

        std::cin.getline(user_choice, 3);

        switch (user_choice[0]) {
        case '1': print_book(book, N);
            break;
        case '2': 
            if (input_name(book, N)) {
            std::cout << "\nName added\n";
            }
            else {
            std::cout << "\nName adding error\n";
            }
                break;
        case '3': sort_name(book, N); break;
        case '0': break;

        }
    } while (user_choice[0] != '0');  // общий цикл по меню, пока пользователь не выберет "выход"

    return 0;   
}

   
int main1() {
    /*
   Є 3 двовимірні масиви A, B, C. Кількість рядків і стовпців вводить користувач з клавіатури для
    кожного з них. Реалізуйте:
    ■ Створіть одновимірний масив, який містить загальні значення для A, B, C;
    ■ Створіть одновимірний масив, який містить унікальні значення для A, B, C;
    ■ Створіть одновимірний масив, який містить загальні значення для A і C;
    ■ Створіть одновимірний масив, який містить від'ємні значення для A, B, C без повторень.
    */
    srand(time(NULL));
    size_t A, B, C, D, E, F;

    std::cout << "Enter size1 and size 2 for 1st 2D array: ";
    std::cin >> A >> B;
    std::cout << "First 2D array\n";
    int** arr1 = create_arr(A, B);
    fill_arr(arr1, A, B);   
    print_arr(arr1, A, B);
    std::cout << "------------------------------------\n";

    std::cout << "Enter size1 and size 2 for 2nd 2D array: ";
    std::cin >> C >> D;
    std::cout << "Second 2D array\n";
    int** arr2 = create_arr(C, D);
    fill_arr(arr2, C, D);    
    print_arr(arr2, C, D);
    std::cout << "------------------------------------\n";

    std::cout << "Enter size1 and size 2 for 3rd 2D array: ";
    std::cin >> E >> F;
    std::cout << "Third 2D array\n";
    int** arr3 = create_arr(E, F);
    fill_arr(arr3, E, F);
    print_arr(arr3, E, F);
    std::cout << "------------------------------------\n";

    size_t count1;
    int* uniqs1 = negative(arr1, arr2, arr3, A, B, C, D, E, F, count1);
    std::cout << "Negative elements: \n";
    for (size_t i = 0; i < count1; i++) {
        std::cout << uniqs1[i] << ' ';
    }
    std::cout << "\n------------------------------------\n";

    size_t count2;
    int* uniqs2 = common_AC(arr1, arr3, A, B, E, F, count2);
    std::cout << "\nCommon elements for AC: \n";
    for (size_t i = 0; i < count2; i++) {
        std::cout << uniqs2[i] << ' ';
    }
    std::cout << "\n------------------------------------\n";

    size_t count3;
    int* uniqs3 = common_ABC(arr1, arr2, arr3, A, B, C, D, E, F, count3);
    std::cout << "\nCommon elements for ABC: \n";
    for (size_t i = 0; i < count3; i++) {
        std::cout << uniqs3[i] << ' ';
    }
    std::cout << "\n------------------------------------\n";

    size_t count4;
    int* uniqs4 = uniq_ABC(arr1, arr2, arr3, A, B, C, D, E, F, count4);
    std::cout << "\nUnique elements for ABC: \n";
    for (size_t i = 0; i < count4; i++) {
        std::cout << uniqs4[i] << ' ';
    }
    std::cout << "\n------------------------------------\n";


    delete_arr(arr1, A);
    delete_arr(arr2, C);
    delete_arr(arr3, E);
    delete[] uniqs1;
    delete[] uniqs2;
    delete[] uniqs3;
    delete[] uniqs4;


    return 0;
}
