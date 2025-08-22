#include <iostream>
using namespace std;

int main() {
    int a[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int m = 0; 
    for(int i = 0; i < n; i++) {
        bool duplicate = false;
        for(int j = 0; j < m; j++) {
            if(a[j] == a[i]) {
                duplicate = true;
                break;
            }
        }
        if(!duplicate) {
            a[m] = a[i];
            m++;
        }
    }

    for(int i = 0; i < m; i++) cout << a[i] << " ";
    cout << "\n";

    return 0;
}
