#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Ввод матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Поиск столбцов без отрицательных элементов и вычисление суммы
    for (int j = 0; j < n; ++j) {
        bool hasNegative = false;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
            sum += matrix[i][j];
        }

        if (!hasNegative) {
            matrix[j][j] = sum; // Замена элемента на главной диагонали
        }
    }

    // Вывод измененной матрицы
    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
17:40 
