#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Sort {
public:
	Sort() {}
	T findMax(T A[], int n);
	void countSort(T arr[], int n, int exp);
	void radixsort(T arr[], int n);
};

template <class T>
T Sort<T>::findMax(T A[], int n) {
	T max = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

template <class T>
void Sort<T>::countSort(T arr[], int n, int exp)
{
	T output[n];
	int i;
	T count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

template <class T>
void Sort<T>::radixsort(T arr[], int n)
{
	T m = findMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

string convertTostring(double x) {
	stringstream s;
	s << x;
	return s.str();
}

int main() {
	double x[] = { 155.5,152.1,131.6,112.9 },n=4;
	string s[4];
	for (int i = 0; i < 4; i++) {
		s[i] = convertTostring(x[i]);
	}
	Sort<string>* a = new Sort<string>();
	a->radixsort(s, 4);
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}

}