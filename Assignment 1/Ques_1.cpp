#include <iostream>
using namespace std;

int main() {
    int a[100], n = 0;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT (0-based position)\n";
        cout << "4. DELETE (0-based position)\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter " << n << " elements: ";
            for(int i=0; i<n; i++) cin >> a[i];
        }
        else if(choice == 2) {
            if(n == 0) cout << "Array empty\n";
            else {
                cout << "Array: ";
                for(int i=0; i<n; i++) cout << a[i] << " ";
                cout << "\n";
            }
        }
        else if(choice == 3) {
            int pos, val;
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            if(pos >= 0 && pos <= n) {
                for(int i=n; i>=pos; i--) {
                    a[i+1] = a[i];
                }
                a[pos] = val;
                n++;
                cout << "Inserted successfully\n";
            } else {
                cout << "Invalid position\n";
            }
        }
        else if(choice == 4) {
            int pos;
            cout << "Enter position (0 to " << n-1 << "): ";
            cin >> pos;
            if(pos >= 0 && pos < n) {
                for(int i=pos; i<n; i++) {
                    a[i-1] = a[i];
                }
                n--;
                cout << "Deleted successfully\n";
            } else {
                cout << "Invalid position\n";
            }
        }
        else if(choice == 5) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            bool found = false;
            for(int i=0; i<n; i++) {
                if(a[i] == key) {
                    cout << "Found at index " << i << "\n";
                    found = true;
                    break;
                }
            }
            if(!found) cout << "Not found\n";
        }

    } while(choice != 6);

    cout << "Exiting...\n";
    return 0;
}
