#include <iostream>
#include <vector>
#include <random>
#include <limits.h>

using namespace std;

bool isNumeric(const string& str){
    if (str[0] == '-'){
      cout << "Can't be negative" << endl;
      return false;
      }
    for(unsigned int a = 0; a < str.size(); a++){
        if (!isdigit(str[a])){
          cout << "Not a valid number" << endl;
          return false;
          }
    }
    return true;
}

int main() {
    string input;
    int n;
    bool flag = false, err = false;
    
    while (!flag) {
      cout << "Введите размер квадратной матрицы: ";
      getline(cin,input);
      if (isNumeric(input)) {
        err = false;
        try {
          n = stoi(input);
          }
        catch (std::out_of_range& e){
          cout << "Out of range" << endl;
          err = true;
          }
        catch (std::invalid_argument& e){
          cout << "No data" << endl;
          err = true;
          }
        if ((!err)&&(n>0)) flag = true;
          else cout << "Can't be null" << endl;
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
