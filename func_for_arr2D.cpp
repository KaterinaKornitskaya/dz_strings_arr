#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<Windows.h>
#include<ctime>

int** create_arr(size_t S, size_t S1) {  // ф-ия, создание 2D массива [S][S1]
    int** arr = new int* [S];
    for (size_t i = 0; i < S; i++) {
        arr[i] = new int[S1];
    }
    return arr;
}

void delete_arr(int** arr, size_t S) {  // ф-ия, освобождение памяти 2D массива [S][S1]
    for (size_t i = 0; i < S; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void fill_arr(int** arr, size_t S, size_t S1) {  // ф-ия, заполнение 2D массива [S][S1]
    for (size_t i = 0; i < S; i++) {
        for (size_t j = 0; j < S1; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

void print_arr(int** arr, size_t S, size_t S1) {  // ф-ия, вывод на экран 2D массива [S][S1]
    for (size_t i = 0; i < S; i++) {
        for (size_t j = 0; j < S1; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int* negative(int** arr1, int** arr2, int** arr3, size_t A, size_t B,
    size_t C, size_t D, size_t E, size_t F, size_t& res_size) {  // ф-ия, создание массива из отрицательных эл-ов
    int count = 0;                    // счетчик для отрицательных элементов
    for (size_t i = 0; i < A; i++) {  // проход циклом по массиву А
        for (size_t j = 0; j < B; j++) {
            if (arr1[i][j] < 0) {
                ++count;
            }
        }
    }

    for (size_t i = 0; i < C; i++) {  // проход циклом по массиву В
        for (size_t j = 0; j < D; j++) {
            if (arr2[i][j] < 0) {
                ++count;
            }
        }
    }

    for (size_t i = 0; i < E; i++) {  // проход циклом по массиву С
        for (size_t j = 0; j < F; j++) {
            if (arr3[i][j] < 0) {
                ++count;
            }
        }
    }

    if (count == 0) {  // если нет отрицательных - вернуть 0
        return NULL;
    }
    int* res = new int[count];  // выделение нужной памяти под общий массив

    count = 0;
    for (size_t i = 0; i < A; i++) {
        for (size_t j = 0; j < B; j++) {
            if (arr1[i][j] < 0) {
                bool in_array = false;
                for (size_t k = 0; k < count; k++) {
                    if (res[k] == arr1[i][j]) {
                        in_array = true;
                    }
                }
                if (!in_array) {  // проверка, чтобы эл-ты не повторялись
                    res[count++] = arr1[i][j];
                }
            }
        }
    }

    for (size_t i = 0; i < C; i++) {
        for (size_t j = 0; j < D; j++) {
            if (arr2[i][j] < 0) {
                bool in_array = false;
                for (size_t k = 0; k < count; k++) {
                    if (res[k] == arr2[i][j]) {
                        in_array = true;
                    }
                }
                if (!in_array) {
                    res[count++] = arr2[i][j];
                }
            }
        }
    }

    for (size_t i = 0; i < E; i++) {
        for (size_t j = 0; j < F; j++) {
            if (arr3[i][j] < 0) {
                bool in_array = false;
                for (size_t k = 0; k < count; k++) {
                    if (res[k] == arr3[i][j]) {
                        in_array = true;
                    }
                }
                if (!in_array) {
                    res[count++] = arr3[i][j];
                }
            }
        }
    }

    res_size = count;
    return res;
}

int* common_AC(int** arr1, int** arr3, size_t A, size_t B,
    size_t E, size_t F, size_t& res_size) {  // ф-ия, общие значения для массивов А С
    int count = 0;
    for (size_t i = 0; i < A; i++) {         // проходим циклом по двум массивам
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < E; k++) {
                for (size_t l = 0; l < F; l++) {
                    if (arr1[i][j] == arr3[k][l]) {
                        ++count;
                    }
                }
            }
        }
    }
    if (count == 0) {
        return NULL;
    }

    int* res = new int[count];

    count = 0;

    for (size_t i = 0; i < A; i++) {
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < E; k++) {
                for (size_t l = 0; l < F; l++) {
                    if (arr1[i][j] == arr3[k][l]) {
                        bool in_array = false;
                        for (size_t k = 0; k < count; k++) {
                            if (res[k] == arr1[i][j]) {
                                in_array = true;
                            }
                        }
                        if (!in_array) {
                            res[count++] = arr1[i][j];
                        }
                    }
                }
            }
        }
    }
    res_size = count;
    return res;

}

int* common_ABC(int** arr1, int** arr2, int** arr3, size_t A, size_t B,
    size_t C, size_t D, size_t E, size_t F, size_t& res_size) {  // ф-ия, общие значения для массивов А В С

    int count = 0;
    for (size_t i = 0; i < A; i++) {  // цикл по трем 2D массивам А В С
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < C; k++) {
                for (size_t l = 0; l < D; l++) {
                    for (size_t m = 0; m < E; m++) {
                        for (size_t n = 0; n < F; n++) {
                            if (arr1[i][j] == arr3[m][n] &&
                                arr1[i][j] == arr2[k][l] &&
                                arr2[k][l] == arr3[m][n]) {
                                ++count;
                            }
                        }
                    }
                }
            }
        }
    }
    if (count == 0) {
        return NULL;
    }

    int* res = new int[count];

    count = 0;

    for (size_t i = 0; i < A; i++) {
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < C; k++) {
                for (size_t l = 0; l < D; l++) {
                    for (size_t m = 0; m < E; m++) {
                        for (size_t n = 0; n < F; n++) {
                            if (arr1[i][j] == arr3[m][n] &&
                                arr1[i][j] == arr2[k][l] &&
                                arr2[k][l] == arr3[m][n]) {
                                bool in_array = false;
                                for (size_t k = 0; k < count; k++) {
                                    if (res[k] == arr1[i][j]) {
                                        in_array = true;
                                    }
                                }
                                if (!in_array) {
                                    res[count++] = arr1[i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    res_size = count;
    return res;
}

int* uniq_ABC(int** arr1, int** arr2, int** arr3, size_t A, size_t B,
    size_t C, size_t D, size_t E, size_t F, size_t& res_size) {  // ф-ия, разные значения для массивов А В С

    int count = 0;
    for (size_t i = 0; i < A; i++) {
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < C; k++) {
                for (size_t l = 0; l < D; l++) {
                    for (size_t m = 0; m < E; m++) {
                        for (size_t n = 0; n < F; n++) {
                            if (arr1[i][j] != arr3[m][n] ||
                                arr1[i][j] != arr2[k][l] ||
                                arr2[k][l] != arr3[m][n]) {
                                ++count;
                            }
                        }
                    }
                }
            }
        }
    }
    if (count == 0) {
        return NULL;
    }

    int* res = new int[count];

    count = 0;

    for (size_t i = 0; i < A; i++) {
        for (size_t j = 0; j < B; j++) {
            for (size_t k = 0; k < C; k++) {
                for (size_t l = 0; l < D; l++) {
                    for (size_t m = 0; m < E; m++) {
                        for (size_t n = 0; n < F; n++) {
                            if (arr1[i][j] != arr3[m][n] ||
                                arr1[i][j] != arr2[k][l] ||
                                arr2[k][l] != arr3[m][n]) {
                                bool in_array = false;
                                for (size_t k = 0; k < count; k++) {
                                    if (res[k] == arr1[i][j]) {
                                        in_array = true;
                                    }
                                }
                                if (!in_array) {
                                    res[count++] = arr1[i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    res_size = count;
    return res;
}

