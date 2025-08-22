#include <iostream>
using namespace std;

int main() {
    int a[100], n, key;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] == key) {
            cout << "Found at index " << mid << "\n";
            found = true;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(!found) cout << "Not found\n";
    return 0;
}
