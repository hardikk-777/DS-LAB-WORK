#include <iostream>
using namespace std;

int main() {
    int A[20][20];
    int r, c;
    cin >> r >> c;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "Row sums: ";
    for(int i = 0; i < r; i++) {
        int sum = 0;
        for(int j = 0; j < c; j++)
            sum += A[i][j];
        cout << sum << " ";
    }
    cout << "\n";

    cout << "Column sums: ";
    for(int j = 0; j < c; j++) {
        int sum = 0;
        for(int i = 0; i < r; i++)
            sum += A[i][j];
        cout << sum << " ";
    }
    cout << "\n";

    return 0;
}
