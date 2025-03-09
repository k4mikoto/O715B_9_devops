#include "input.h"

bool isNumeric(const string& str){
    if (str[0] == '-'){
      cout << "Can't be negative" << endl;
      return false;
      }
    for(int a = 0; a < str.size(); a++){
        if (!isdigit(str[a])){
          cout << "Not a valid number" << endl;
          return false;
          }
    }
    return true;
}

int getsize(){
  int n;
  string input;
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
      return n;
}
