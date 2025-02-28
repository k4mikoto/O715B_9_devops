#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool isNumeric(const string& str){
    for(int a = 0; a < str.size(); a++){
        if (!isdigit(str[a]))
           return false;
    }
    return true;
}

int main() {
    string input;
    int n, temp;
    bool flag = false;
    
    while (!flag) {
      cout << "Введите размер квадратной матрицы: ";
      getline(cin,input);
      if (isNumeric(input)) {
      n = stoi(input);
      flag = true;
      }
    }

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
