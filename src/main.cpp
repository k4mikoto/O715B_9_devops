#include "input.h"

int main() {
    int n;
    
    n = getsize();
    vector<vector<int>> matrix(n, vector<int>(n));
    
    std::random_device rseed;
    std::mt19937 rng(rseed());
    std::uniform_int_distribution<int> dist(-100,100);
        
    //zapolnenie
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = dist(rng);
        }
    }
    
    // Вывод матрицы
    cout << "Изначальная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

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
