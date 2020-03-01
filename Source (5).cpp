#include <iostream>
using namespace std;

template <class T>
class Sort {
public:
	Sort() {}
	void swap(T* a, T* b);
	void BubbleSort(T A[], int n);
	void SelectionSort(T A[], int n);
	void InsertionSort(T A[], int n);
	T Partition(T A[], int l, int h);
	void QuickSort(T A[], int l, int h);
	void Merge(T A[], int l, int mid, int h);
	void MergeSort(T A[], int l, int h);
	T findMax(T A[], int n);
	void Display(T A[], int n);
	void ReverseDisplay(T A[], int n);
};

template <class T>
void Sort<T>::swap(T *a,T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void Sort<T>::BubbleSort(T A[],int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);
		}
	}
}

template <class T>
void Sort<T>::SelectionSort(T A[], int n) {
	T MAX;
	for (int i = 0; i < n - 1; i++) {
		for (T j = MAX = i; j < n; j++) {
			if (A[j] < A[MAX]) {
				MAX = j;
			}
		}
		swap(&A[i], &A[MAX]);
	}
}

template <class T>
void Sort<T>::InsertionSort(T A[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		T x = A[i];
		while (j > -1 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

//quicksort
template <class T>
T Sort<T>::Partition(T A[], int l, int h) {
	T pivot = A[l];
	int i = l, j=h;
	do {
		do { i++; } while (A[i] <= pivot);
		do { j--; } while (A[j] > pivot);
		if (i < j)
			swap(&A[i], &A[j]);
	} while (i < j);
	swap(&A[l], &A[j]);
	return j;
}

template <class T>
void Sort<T>::QuickSort(T A[], int l, int h) {
	int j;
	if (l < h) {
		j = Partition(A,l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

template <class T>
void Sort<T>::Merge(T A[], int l, int mid, int h)
{
	int i = l, j = mid + 1, k = l;
	T B[100];
	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for (; i <= mid; i++)
		B[k++] = A[i];
	for (; j <= h; j++)
		B[k++] = A[j];
	for (i = l; i <= h; i++)
		A[i] = B[i];
}

template <class T>
void Sort<T>::MergeSort(T A[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		MergeSort(A, l, mid);
		MergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

template <class T>
T Sort<T>::findMax(T A[], int n) {
	T max = T32_MIN;
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

template <class T>
void Sort<T>::Display(T A[],int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

template <class T>
void Sort<T>::ReverseDisplay(T A[], int n) {
	for (int i = n-1; i >=0; i--) {
		cout << A[i] << " ";
	}
	cout << endl;
}



int main() {
	int choice1, choice2,choice3,choice4;
	cout << "Which data type you want to perform sorting on(1.long,2.float,3.strings)?" << endl;
	cin >> choice1;
	cout << "How many elements you want to sort?" << endl;
	cin >> choice2;
	cout << "Enter the elements you want to sort" << endl;
	if (choice1 == 1) {
		Sort<long> a();
		long* B = new long[choice2];
		for (int i = 0; i < choice2; i++) {
			cin >> B[i];
		}
	}
	else if (choice1 == 2) {
		Sort<float> a();
		float* B = new float[choice2];
		for (int i = 0; i < choice2; i++) {
			cin >> B[i];
		}
	}
	else if (choice1 == 3) {
		Sort<string> a();
		string* B = new string[choice2];
		for (int i = 0; i < choice2; i++) {
			cin >> B[i];
		}
	}

	cout << "Which type of sorting you want to perform(1.bubble sort 2.Insertion sort 3.selection sort, 4.merge sort, 5.Quick sort, 6.Radix sort)?" << endl;
	cin >> choice3;
	if (choice3 == 1)
		a.bubbleSort(B, choice2);
	else if (choice3 == 2)
		a.InsertionSort(B, choice2);
	else if (choice3 == 3)
		a.selectionSort(B, choice2);
	else if (choice3 == 4)
		a.MergeSort(B, choice2);
	if (choice3 == 5)
		a.QuickSort(B, choice2);
	if (choice3 == 6)
		a.RadixSort(B, choice2);

	cout << "Do you want to sort in Ascending or Descending(1.Ascending 2.Descending)"<<endl;
	cin >> choice3;
	if (choice4 == 1)
		a.Display(B,choice2); //display the sorted elements in ascending order
	else if (choice4 == 2)
		a.ReverseDisplay(B,choice2);// would display the sorted elements in descending order


}

