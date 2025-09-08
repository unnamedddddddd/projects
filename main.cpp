#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace std;

float TwoDivision(float a, float b);

int main(){
    try
    {
        float first = 0, second = 0;
        cout << "Первое число:" ; cin >> first; 
        cout << "Второе число:" ; cin >> second; 

        cout << TwoDivision(first,second) << endl;
    }catch(const underflow_error& e)
    {
        std::cerr << "Ошибка: "<< e.what() << '\n';
    }catch(const exception& e)
    {
        std::cerr << "Ошибка: "<< e.what() << '\n';
    }
    return 0;
}

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
   
