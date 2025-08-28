#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    // Since array is sorted and starts with 1
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] != arr[i] + 1) {
            return arr[i] + 1; // missing number
        }
    }
    return -1; // no missing number
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " sorted elements (with one missing in sequence): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int missing = findMissing(arr, n);

    if (missing != -1)
        cout << "Missing number is: " << missing << endl;
    else
        cout << "No missing number detected." << endl;

    return 0;
}
