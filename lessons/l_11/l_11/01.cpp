/* —оздайте 2 перегруженные функции Ц одна принимает массив char и возвращает его в обратном
пор€дке; втора€ Ц принимает массив char и число n и возвращает n символов с конца исходного
массива (тоже в обратном пор€дке).

#include <iostream>

using namespace std;

char* reverseArray(const char* src, const int size) {
	char* dest = new char[size];

	for (int i = 0; i < size; ++i) {
		dest[size - i - 1] = src[i];
	}

	return dest;
}

char* reverseArray(const char* src, const int size, const int n) {
	if (n > size) return reverseArray(src, size);
	else if (n <= 0) cout << "Wrong n!" << endl;
	else {
		char* dest = new char[n];

		for (int i = 0; i < n; ++i) {
			dest[n - i - 1] = src[size - n + i];
		}

		return dest;
	}
}

int main() {
	const char SRC_ARRAY[] = { 'a', 'b', 'c' };
	const int SIZE = 3;
	const int n = 2;

	char* newArray0 = reverseArray(SRC_ARRAY, SIZE);
	for (int i = 0; i < SIZE; ++i) { cout << newArray0[i]; }

	cout << endl;

	char* newArray1 = reverseArray(SRC_ARRAY, SIZE, n);
	for (int i = 0; i < n; ++i) { cout << newArray1[i]; }

	delete[] newArray0;
	delete[] newArray1;
	return 0;
} */