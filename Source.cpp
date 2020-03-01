#include <iostream>
using namespace std;

void swap(int* a,int* b) {
	int tem;
	tem = *a;
	*a = *b;
	*b = tem;
}

void bubbleSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}

void InsertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = A[i];
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
}

void selectionSort(int A[], int n) {
	int j, least;
	for (int i = 0; i < n - 1; i++) {
		for (j = least = i; j < n; j++) {
			if (A[j] < A[least]) {
				least = j;
			}
		}
		swap(&A[i], &A[least]);
	}
}

int Partition(int A[], int l, int h) {
	int pivot = A[l];
	int i = l, j = h;
	do {
		do { i++; } while (A[i] <= pivot);
		do{ j--; } while (A[j] > pivot);
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
	int i, j, k;
	int B[10] = { 0 };
	i = l, j = mid + 1, k = l;
	while (i <= mid && j <= h) {
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
	k = 0;
	for (int i = l; i <= h; i++) {
		A[i] = B[k++];
	}
}

void MergeSort(int A[], int l, int h) {
	int mid;
	if (l < h) {
		mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

void display(int A[], int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main() {
	int A[] = { 7,6,5,4,9,8,3,1 },n=8;
	MergeSort(A,0, n);
	display(A, n);
}