#include <iostream>
using namespace std;

void Merging(int A[], int l, int mid, int h) {
	int i, j, k;
	int	B[6] = { 0,0,0,0,0,0};
	i = l, j = mid + 1, k = l;
	while (i <= mid && j <= h) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
	for (; i <= mid; i++) {
		B[k++] = A[i];
	}

	for (; j <= h; j++) {
		B[k++] = A[j];
	}
	for (int i = 0; i <= h; i++) {
		A[i] = B[i];
		cout << A[i] << " ";
	}
}


int main() {
	int A[] = { 2,4,6,1,3,8,10 };
	Merging(A, 0, 2, 6);

}