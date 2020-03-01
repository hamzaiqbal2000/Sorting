//selection sort
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int A[], int n) {
	int i,least,j;
	for (i = 0; i < n-1; i++) {
		for (j = least = i; j < n; j++) {
			if (A[j] < A[least]) {
				least = j;
			}
		}
		swap(&A[i], &A[least]);
	}
}

int main() {
	int A[] = {3,6,8,9,1,2},n=6;
	SelectionSort(A, n);
	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
}