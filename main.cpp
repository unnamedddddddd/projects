#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

float TwoDivision(float first, float second){
    float min_float = numeric_limits<float>::min();
    if (second == 0)
    {
        throw runtime_error("Деление на 0");
    }
    float res = first / second;
    if (res < min_float) throw underflow_error("Результат меньше допустимого значения");
    else return res;

return 0;
}

int main(){
    try{
        int choice = 1;
        do{
            float first = 0, second = 0;
            cout << "Первое число:" ; cin >> first; 
            if(cin.fail()){
                cout << "Ошибка: не тот тип " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
            cout << "Второе число:" ; cin >> second;
            if(cin.fail()){
                cout << "Ошибка: не тот тип " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
            cout << TwoDivision(first,second) << endl;
            cout << "Продолжить?(1 - продолжить, 0 - конец)"<<endl;cin >> choice;
        }while(choice == 1);
    }catch(const underflow_error& e)
    { 
        cerr << "Ошибка: "<< e.what() << '\n';
        return 0;
    }catch(const exception& e)
    {
        cerr << "Ошибка: "<< e.what() << '\n';
        return 0;
    }
return 0;
}
