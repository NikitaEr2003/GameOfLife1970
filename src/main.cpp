#include "Cour.h"
#include <Windows.h>
#include <string>

using namespace std;
int main() {

    ifstream file;
    file.open("game.txt");

    int rows, cols;
    file >> rows;
    file >> cols;

    int** arr = CreateArray(rows, cols);
    EditFirstArray(arr, rows, cols);

    int num = 0;
    int num1 = 1;

    while (file >> num >> num1) {
        arr[num][num1] = 1;
    }
    file.close();
    int count = 0;
    string str;


    while (true) {

        int cells = PrintArray(arr, rows, cols);
        bool answer = false;
        cout << endl;
        if (cells == 0) {
            str = "All Died";
            cout << "Generation: " << count++ << " " << "Alive cells: " << cells << endl;
            cout << str << endl;

            break;;
        }
        else {
            str = " ";
        }

        cout << "Generation: " << ++count << " " << "Alive cells: " << cells << endl;

        cout << str << endl;
        arr = NextStep(arr, rows, cols, answer);
        if (answer == true) {
            cout << "Cells do not change the cycle is interrupted\n";
            break;

        }
        Sleep(2000);
        system("cls");



    }
    DeleteArray(arr, rows, cols);
    system("pause");
    return 0;

}
