//bubble sort
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bubbleSort(int A[], int n) {
	int flag;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

int main() {
	int A[] = { 5,4,3,6,7,1,2,9 },n=8;
	bubbleSort(A,n);
	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
	return 0;
}