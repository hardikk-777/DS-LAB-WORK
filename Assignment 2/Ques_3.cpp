#include <iostream>
using namespace std;

int main() {
    int a[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int start = a[0];
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int expected = start + mid;

        if(a[mid] == expected) {
            low = mid + 1; // Missing number is on the right
        } else {
            high = mid - 1; // Missing number is on the left
        }
    }

    cout << "Missing number is " << (start + low) << "\n";

    return 0;
}
