#include "Cour.h"
#include "Const.h"

bool ArraysEqual(int** arr1, int** arr2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr1[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void DeleteArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
}

int** CreateArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]();
    }
    return arr;
}

void EditFirstArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;

        }
    }

}

int PrintArray(int** arr, int rows, int cols) {
    using namespace std;
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 1) {
                cout << Constss::IsLife;
                count++;
            }
            else {
            cout << Constss::IsDead;
            }
        } cout << endl;
    }
    return count;
}

void Copy(int** scr, int** dst, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dst[i][j] = scr[i][j];
        }
    }
}

inline int Get_X(int num, int parametr) {
    return (parametr + num) % parametr;
}

int** NextStep(int** arr, int rows, int cols, bool& answer) {
    int** next = CreateArray(rows, cols);

    Copy(arr, next, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sumfriend = 0;

            sumfriend += next[Get_X(i - 1, rows)][Get_X(j - 1, cols)];
            sumfriend += next[Get_X(i - 1, rows)][Get_X(j, cols)];
            sumfriend += next[Get_X(i - 1, rows)][Get_X(j + 1, cols)];

            sumfriend += next[Get_X(i, rows)][Get_X(j - 1, cols)];
            sumfriend += next[Get_X(i, rows)][Get_X(j + 1, cols)];

            sumfriend += next[Get_X(i + 1, rows)][Get_X(j - 1, cols)];
            sumfriend += next[Get_X(i + 1, rows)][Get_X(j, cols)];
            sumfriend += next[Get_X(i + 1, rows)][Get_X(j + 1, cols)];

            if ((next[i][j] == 0) && (sumfriend == 3)) {
                arr[i][j] = 1;
            }
            else if (sumfriend < 2 || sumfriend > 3) {
                arr[i][j] = 0;
            }
        }
    }

    answer = ArraysEqual(arr, next, rows, cols);

    DeleteArray(next, rows, cols);
    return arr;
}