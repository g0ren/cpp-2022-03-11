#include <iostream>
#include <cstdio>
#include <ctime>
#define MIN_N -50
#define MAX_N 50
using namespace std;

/*
 * Есть 3 двумерных массива A, B, C. Количество
 строк и столбцов для них вводит пользователь с клавиа-
 туры для каждого из них. Реализуйте
 ■ ■ Создайте одномерный массив, который содержит
 общие значения для A, B, C;
 ■ ■ Создайте одномерный массив, который содержит
 уникальные значения для A, B, C;
 ■ ■ Создайте одномерный массив, который содержит
 общие значения для A и C;
 ■ ■ Создайте одномерный массив, который содержит
 отрицательные значения для A, B, C без повторений.
 *
 */

int** createArray(int **a, int isize, int jsize) {
	int **ar = new int*[isize] { };
	for (int i = 0; i < isize; i++) {
		ar[i] = new int[jsize] { };
	}
	return ar;
}

void fillArray(int **ar, int isize, int jsize) {
	for (int i = 0; i < isize; i++) {
		for (int j = 0; j < jsize; j++) {
			ar[i][j] = MIN_N + (MAX_N - MIN_N) * ((double) rand() / RAND_MAX);
		}
	}
}

void printArray(int **ar, int isize, int jsize) {
	for (int i = 0; i < isize; i++) {
		for (int j = 0; j < jsize; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}

void printArray(int *ar) {
	for (int i = 1; i < ar[0]; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
}

bool in(int **ar, int isize, int jsize, int el) {
	for (int i = 0; i < isize; i++)
		for (int j = 0; j < jsize; j++)
			if (ar[i][j] == el)
				return true;
	return false;
}

int* addElem(int *ar, int el) {
	int *r = new int[ar[0] + 1];
	r[0] = ar[0] + 1;
	for (int i = 1; i < ar[0]; i++) {
		r[i] = ar[i];
	}
	r[ar[0]] = el;
	delete[] ar;
	return r;
}

/*
 * Создайте одномерный массив, который содержит
 общие значения для A, B, C;
 */
int* intersection(int **a, int **b, int **c, int ai, int aj, int bi, int bj,
		int ci, int cj) {
	int *r = new int[1] { 1 };
	for (int i = 0; i < ai; i++)
		for (int j = 0; j < aj; j++)
			if (in(b, bi, bj, a[i][j]) && in(c, ci, cj, a[i][j]))
				r = addElem(r, a[i][j]);
	return r;
}

/*
 * Создайте одномерный массив, который содержит
 уникальные значения для A, B, C;
 */
int* xorsection(int **a, int **b, int **c, int ai, int aj, int bi, int bj,
		int ci, int cj) {
	int *r = new int[1] { 1 };
	for (int i = 0; i < ai; i++)
		for (int j = 0; j < aj; j++)
			if (!in(b, bi, bj, a[i][j]) && !in(c, ci, cj, a[i][j]))
				r = addElem(r, a[i][j]);
	for (int i = 0; i < bi; i++)
		for (int j = 0; j < bj; j++)
			if (!in(a, ai, aj, b[i][j]) && !in(c, ci, cj, b[i][j]))
				r = addElem(r, b[i][j]);
	for (int i = 0; i < ci; i++)
		for (int j = 0; j < cj; j++)
			if (!in(b, bi, bj, c[i][j]) && !in(a, ai, aj, c[i][j]))
				r = addElem(r, c[i][j]);
	return r;
}

/*
 * Создайте одномерный массив, который содержит
 общие значения для A и C;
 */
int* intersection(int **a, int **c, int ai, int aj, int ci, int cj) {
	int *r = new int[1] { 1 };
	for (int i = 0; i < ai; i++)
		for (int j = 0; j < aj; j++)
			if (in(c, ci, cj, a[i][j]))
				r = addElem(r, a[i][j]);
	return r;
}

/*
 * Создайте одномерный массив, который содержит
 отрицательные значения для A, B, C без повторений.
 */
bool in(int *ar, int el) {
	for (int i = 1; i < ar[0]; i++)
		if (ar[i] == el)
			return true;
	return false;
}

int* uniqueNegative(int **a, int **b, int **c, int ai, int aj, int bi, int bj,
		int ci, int cj) {
	int *r = new int[1] { 1 };
	for (int i = 0; i < ai; i++)
		for (int j = 0; j < aj; j++)
			if (a[i][j] < 0 && !in(r, a[i][j]))
				r = addElem(r, a[i][j]);
	for (int i = 0; i < bi; i++)
		for (int j = 0; j < bj; j++)
			if (b[i][j] < 0 && !in(r, b[i][j]))
				r = addElem(r, b[i][j]);
	for (int i = 0; i < ci; i++)
		for (int j = 0; j < cj; j++)
			if (c[i][j] < 0 && !in(r, c[i][j]))
				r = addElem(r, c[i][j]);
	return r;
}

void deleteArray(int **ar, int sizei) {
	for (int i = 0; i < sizei; i++)
		delete[] ar[i];
	delete[] ar;
}

int main() {
	int **a { }, **b { }, **c { };
	int ai { }, aj { }, bi { }, bj { }, ci { }, cj { };
	cout << "Enter sizes of A:" << endl;
	cin >> ai >> aj;
	cout << "Enter sizes of B:" << endl;
	cin >> bi >> bj;
	cout << "Enter sizes of C:" << endl;
	cin >> ci >> cj;
	a = createArray(a, ai, aj);
	b = createArray(a, bi, bj);
	c = createArray(c, ci, cj);
	fillArray(a, ai, aj);
	fillArray(b, bi, bj);
	fillArray(c, ci, cj);
	cout << "A:" << endl;
	printArray(a, ai, aj);
	cout << "B:" << endl;
	printArray(b, bi, bj);
	cout << "C:" << endl;
	printArray(c, ci, cj);
	int *inter = intersection(a, b, c, ai, aj, bi, bj, ci, cj);
	cout << "intersection(A,B,C):" << endl;
	printArray(inter);
	cout << "xor(A,B,C):" << endl;
	int *xors = xorsection(a, b, c, ai, aj, bi, bj, ci, cj);
	printArray(xors);
	cout << "intersection(A,C):" << endl;
	int *inter2 = intersection(a, c, ai, aj, ci, cj);
	printArray(inter2);
	cout << "unique negative elements of A,B,C:" << endl;
	int *un = uniqueNegative(a, b, c, ai, aj, bi, bj, ci, cj);
	printArray(un);
	deleteArray(a, ai);
	deleteArray(b, bi);
	deleteArray(c, ci);
	delete[] inter;
	delete[] xors;
	delete[] inter2;
	delete[] un;
	return 0;
}
