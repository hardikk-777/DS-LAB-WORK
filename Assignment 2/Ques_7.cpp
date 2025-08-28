//7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion  if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of inversions in an array.

#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = countInversions(arr, n);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
