#include <iostream>
using namespace std; 

// void minMax(int* ptr, int size); // #1
void fillArray(int* ptr, int size);
void displayArray(int* ptr, int size);
// void negPosZero(int* ptr, int size); // #2

int main()
{
	srand(time(nullptr));
	// int size = 3; // #1
	int size = 10; // #3
	/*cout << "Enter the size of the array: ";
	cin >> size;*/ //#2
	int* ptr = new int[size];
	fillArray(ptr, size);
	displayArray(ptr, size);
	// negPosZero(ptr, size); //#2
	// minMax(ptr, size); #1

}
void fillArray(int* ptr, int size)
{
	for (int i = 0; i < size; ++i) {
		ptr[i] = -5 + rand() % 11;
	}

}
void displayArray(int* ptr, int size) 
{
	for (int i = 0; i < size; ++i) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}

//void negPosZero(int* ptr, int size) // #2
//{
//	int neg = 0, pos = 0, zero = 0; 
//	for (int i = 0; i < size; ++i) {
//		if (ptr[i] < 0) neg++;
//		else if (ptr[i] > 0) pos++;
//		else zero++;
//	}
//	cout << "Negative nums: " << neg << ". Positive nums: " << pos << ". Zeros: " << zero;
//}

//void minMax(int* ptr, int size) // #1
//{
//	int min = 11, max=0;
//	for (int i = 0; i < size; ++i) {
//		if (ptr[i] >= max) max = ptr[i];
//		if (ptr[i] <= min) min = ptr[i];
//	}
//	cout << "The max num is " << max << ". The min num is " << min;
//}
