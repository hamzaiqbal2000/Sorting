#include <iostream>
using namespace std;


int findMax(int A[], int n) {
	int max = INT32_MIN;
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

void countSort(int A[], int n) {
	int max, * C;
	max = findMax(A, n);
	C = new int[max + 1];

	for (int i = 0; i < max+1; i++) {
		C[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}
	int i=0, j = 0;
	while (i < max+1) {
		if (C[i] > 0) {
			A[j++] = i;
			C[i]--;
		}
		else {
			i++;
		}
	}
}


void RcountSort(int A[], int n, int exp) {
	int count[10];
	int* output = new int[n];
	//initialize the count array with zeros
	for (int i = 0; i < 10; i++) {
		count[i] = 0;
	}
	// for adding the number of times last digit of a umber is present in array 
	for (int i = 0; i < n; i++) {
		count[(A[i] / exp) % 10]++;
	}
	//cummulative frequency
	for (int i = 1; i < 10; i++) {
		count[i] = count[i] + count[i - 1];
	}
	//building the output
	for (int i = n - 1; i >= 0; i--) {
		output[count[(A[i] / exp) % 10]-1] = A[i];
		count[(A[i] / exp) % 10]--;
	}
	//copying the new output array into array A
	for (int i = 0; i < n; i++) {
		A[i] = output[i];
	}

}

void radixSort(int A[], int n) {
	int  max;
	//find max in the array
	max = findMax(A, n);
	for (int exp = 1; max / exp > 0; exp = exp * 10) {//for loop will run as the no. of digits
		RcountSort(A, n, exp);
	}
}

void Display(int A[],int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
}
int main() {
	int A[] = { 9,8,7,6,5,4,3,2 },n=8;
	radixSort(A, n);
	Display(A, n);

}