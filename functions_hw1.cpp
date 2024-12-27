#include <iostream>
using namespace std; 

// void minMax(int* ptr, int size); // #1
void fillArray(int* ptr, int size);
void displayArray(int* ptr, int size);

int main()
{
	srand(time(nullptr));
	int size = 3;
	int* ptr = new int[size];
	fillArray(ptr, size);
	displayArray(ptr, size);
	// minMax(ptr, size); #1

}
void fillArray(int* ptr, int size)
{
	for (int i = 0; i < size; ++i) {
		ptr[i] = 1 + rand() % 10;
	}

}
void displayArray(int* ptr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}

//void minMax(int* ptr, int size) // #1
//{
//	int min = 11, max=0;
//	for (int i = 0; i < size; ++i) {
//		if (ptr[i] >= max) max = ptr[i];
//		if (ptr[i] <= min) min = ptr[i];
//	}
//	cout << "The max num is " << max << ". The min num is " << min;
//}
