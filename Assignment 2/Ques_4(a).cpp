//(a) Write a program to concatenate one string to another string. 

#include <iostream>
#include <cstring> // for strcat
using namespace std;

int main() {
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    strcat(str1, str2); // joins str2 at the end of str1

    cout << "Concatenated string: " << str1 << endl;

    return 0;
}
