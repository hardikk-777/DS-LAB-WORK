//(e) Write a program to convert a character from uppercase to lowercase.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string in UPPERCASE: ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
    }

    cout << "Lowercase string: " << str << endl;
    return 0;
}
