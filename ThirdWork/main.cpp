#include <thread>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;

void File(int res_arr[]) {
	ofstream input("data.txt");

	if (input.is_open())
	{
		for (int i = 0; i < 250000000; ++i)
		{
			input << res_arr[i] << " ";
		}
	}
	else
	{
		cout << "Файл не был открыт";
	}
}

void TwoArrays(int arr1[], int arr2[]) {
	auto start = chrono::high_resolution_clock::now();
	int* res_arr{ new int[250000000] {} };

	for (int i = 0; i < 250000000; ++i)
	{
		res_arr[i] = arr1[i] + arr2[i];
	}

	auto end = chrono::high_resolution_clock::now();
	auto res_time = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << res_arr[10] << " time: " << res_time.count() << " ms" << endl;
}

int main() {
	int num_threads;
	cout << "Введите число потоков(от 1 - 4)";
	while (!(cin >> num_threads) || (num_threads < 1 || num_threads > 4)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Ошибка: Неверный формат. Введите число: ";
    }
	
	int* arr1{ new int [250000000] {} };
	int* arr2{ new int[250000000] {} };

	for (int i = 0; i < 250000000; ++i)
	{
		arr1[i] += i;
		arr2[i] += i;
	}
	vector<thread> threads;
	threads.reserve(num_threads);

	for (int i = 0; i < num_threads; ++i)
	{
		threads.emplace_back(TwoArrays,arr1,arr2);
	}

	// thread th1(TwoArrays, arr1, arr2);
	// thread th2(TwoArrays, arr1, arr2);
	// thread th3(TwoArrays, arr1, arr2);
	// thread th4(TwoArrays, arr1, arr2);

	for (auto& thread : threads) {         
		thread.join();                        
	}

	// th1.join();
	// th2.join();
	// th3.join();
	// th4.join();

}