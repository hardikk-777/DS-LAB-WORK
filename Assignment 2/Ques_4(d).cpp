//(d) Write a program to sort the strings in alphabetical order. 

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char arr[20][50]; // up to 20 strings, each max length 50
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble sort on strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
