#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace std;

float TwoDivision(float a, float b);

int main(){
    try
    {
        float a = 0, b = 0;
        cin >> a >> b;
        cout << TwoDivision(a,b) << endl;
    }catch(const std::underflow_error& e)
    {
        std::cerr << "Ошибка: "<< e.what() << '\n';
    }catch(const std::exception& e)
    {
        std::cerr << "Ошибка: "<< e.what() << '\n';
    }
    return 0;
}

float TwoDivision(float a, float b){
    float min_float = numeric_limits<float>::lowest();
    if (a == 0 || b == 0)
    {
        throw runtime_error("Деление на 0");
    }
    else if (a > min_float  && b > min_float)
    {
        if (a > b) return a / b;
        else return b / a;
    }
    else throw runtime_error("Переполнение");
    return 0;
}