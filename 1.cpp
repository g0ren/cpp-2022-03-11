#include <iostream>
using namespace std;
#define SIZE 5

/*
 * Задание 1. Написать программу, которая дает пользова-
 телю ввести 5 фамилий студентов, а затем сортирует их
 по возрастанию.
 *
 */

char** createArray(char **a) {
	char **ar = new char*[SIZE] { };
	for (int i = 0; i < SIZE; i++) {
		ar[i] = new char[256] { };
		cout << "Enter surname #" << i + 1 << ": ";
		cin.getline(ar[i], 256);
	}
	return ar;
}

void printArray(char **ar) {
	for (int i = 0; i < SIZE; i++) {
		cout << ar[i] << endl;
	}
}

bool lessThan(char *a1, char *a2) {
	for (char *i { a1 }, *j { a2 }; *i || *j; i++, j++) {
		if (*i < *j)
			return true;
		if (*i > *j)
			return false;
	}
	return false;
}

void swap(char **ar, int i, int j) {
	char *t { };
	t = ar[i];
	ar[i] = ar[j];
	ar[j] = t;
}

void sortArray(char **ar) {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < SIZE; i++) {
			if (lessThan(ar[i], ar[i - 1])) {
				sorted = false;
				swap(ar, i, i - 1);
			}
		}
	}

}

void deleteArray(char **ar) {
	for (int i = 0; i < SIZE; i++) {
		delete[] ar[i];
	}
	delete[] ar;
}

int main() {
	char **ar { };
	ar = createArray(ar);
	cout << "Unsorted array:" << endl;
	printArray(ar);
	cout << endl;
	cout << "Sorted array:" << endl;
	sortArray(ar);
	printArray(ar);
	deleteArray(ar);
	return 0;
}
