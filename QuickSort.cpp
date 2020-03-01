//quicksort
#include <iostream>
using namespace std;


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[], int l, int h) {
	int pivot = A[l];
	int i = l, j = h;
	do {
		do {
			i++;
		} while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);
		if (i < j) {
			swap(&A[i], &A[j]);
		}
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}

void Quicksort(int A[], int l, int h) {
	int j;
	if (l < h) {
		j = partition(A, l, h);
		Quicksort(A, l, j);
		Quicksort(A, j + 1, h);
	}
}

int main() {
	int A[] = { 5,3,6,7,2,1,9,8,INT32_MAX },n=9;
	Quicksort(A, 0, n - 1);
	for (int i = 0; i < n-1; i++) {
		cout << A[i] << " ";
	}
}