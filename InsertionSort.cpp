//Insertion Sort
#include <iostream>
using namespace std;

void InsertionSort(int A[], int n) {
	int x, j;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		x = A[i];
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

int main() {
	int A[] = { 5,4,6,7,3,2,1 }, n = 7;
	InsertionSort(A, 7);
	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
	return 0;
}