#include <iostream>
#include <thread>
#include <string>
#include <fstream>

using namespace std;

class Class
{

public:
    void twoth(){
        cout << "id:" << this_thread::get_id() << endl;
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
    }

    int twoth2(){
        int res;
        
        cout << "id:" << this_thread::get_id() << endl;
        cout << "1" << endl;
        cout << "2   " << endl;
        cout << "3" << endl;
        return 10;
    }
};





int main(){
    Class class1;
    int res = 0;

    thread th1(&Class::twoth, class1);
    thread th2([&](){
        res = class1.twoth2();
    });

    th1.join();
    th2.join();

    cout << res;
}