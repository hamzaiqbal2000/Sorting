#include <iostream>
using namespace std;


void swap( int* a,int* b ){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int A[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}

void SelectionSort(int A[], int n) {
	int least;
	for (int i = 0; i < n - 1; i++) {
		for (int j =least= 0; j < n; j++) {
			if (A[j] > A[least])
				least = j;
		}
		swap(&A[i], &A[least]);
	}
}

void InsertionSort(int A[], int n) {
	int j,x;
	for (int i = 1; i < n - 1; i++) {
		x = A[i];
		j = i - 1;
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

int Partition(int A[], int l, int h) {
	int i = l, j = h, pivot = l;
	do {
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);
		if (i < j) {
			swap(&A[i], &A[j]);
		}
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h) {
	int j;
	if (l < h) {
		j = Partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

void Merge(int A[], int l, int mid, int h) {
	int i = l, j = mid + 1, k = l;
	int B[10];
	while (i <= mid && j < h) {
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for (; i <= mid; i++) {
		B[k++] = A[i];
	}
	for (; j <= h; j++) {
		B[k++] = A[j];
	}

	for (int i = l; i < h; i++) {
		A[i] = B[k++];
	}
}

void MergeSort(int A[], int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}