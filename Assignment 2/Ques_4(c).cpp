//(c) Write a program to delete all the vowels from the string.

#include <iostream>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    char result[100];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}
