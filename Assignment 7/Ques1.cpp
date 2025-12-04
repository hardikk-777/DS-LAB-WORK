//selection_sort
/* #include <iostream>
using namespace std;

class SelectionSort {
public:
    void sort(int a[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j)
                if (a[j] < a[minIdx]) minIdx = j;
            if (minIdx != i) swap(a[i], a[minIdx]);
        }
    }
    void print(int a[], int n) {
        for (int i = 0; i < n; ++i) cout << a[i] << (i+1==n?'\n':' ');
    }
};

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    SelectionSort s;
    s.sort(arr, n);
    s.print(arr, n);
    delete[] arr;
    return 0;
}
 */

 //insertion_sort
/* #include <iostream>
using namespace std;

class InsertionSort {
public:
    void sort(int a[], int n) {
        for (int i = 1; i < n; ++i) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j+1] = a[j];
                --j;
            }
            a[j+1] = key;
        }
    }
    void print(int a[], int n) {
        for (int i = 0; i < n; ++i) cout << a[i] << (i+1==n?'\n':' ');
    }
};

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    InsertionSort s;
    s.sort(arr, n);
    s.print(arr, n);
    delete[] arr;
    return 0;
}
 */

 //bubble_sort

 #include <iostream>
using namespace std;

/* class BubbleSort {
public:
    void sort(int a[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    void print(int a[], int n) {
        for (int i = 0; i < n; ++i) cout << a[i] << (i+1==n?'\n':' ');
    }
};

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    BubbleSort s;
    s.sort(arr, n);
    s.print(arr, n);
    delete[] arr;
    return 0;
} */

//merge_sort

/* #include <iostream>
using namespace std;

class MergeSort {
    void merge(int a[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i < n1; ++i) L[i] = a[l + i];
        for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) a[k++] = L[i++];
            else a[k++] = R[j++];
        }
        while (i < n1) a[k++] = L[i++];
        while (j < n2) a[k++] = R[j++];
        delete[] L; delete[] R;
    }
    void ms(int a[], int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        ms(a, l, m);
        ms(a, m+1, r);
        merge(a, l, m, r);
    }
public:
    void sort(int a[], int n) { ms(a, 0, n-1); }
    void print(int a[], int n) { for (int i=0;i<n;++i) cout<<a[i]<<(i+1==n?'\n':' '); }
};

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    MergeSort s;
    s.sort(arr, n);
    s.print(arr, n);
    delete[] arr;
    return 0;
} */


//quick_sort

/* #include <iostream>
using namespace std;

class QuickSort {
    int partition(int a[], int low, int high) {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (a[j] <= pivot) swap(a[++i], a[j]);
        }
        swap(a[i+1], a[high]);
        return i+1;
    }
    void qs(int a[], int low, int high) {
        if (low < high) {
            int pi = partition(a, low, high);
            qs(a, low, pi-1);
            qs(a, pi+1, high);
        }
    }
public:
    void sort(int a[], int n) { qs(a, 0, n-1); }
    void print(int a[], int n) { for (int i=0;i<n;++i) cout<<a[i]<<(i+1==n?'\n':' '); }
};

int main() {
    int n; cin >> n;
    int* arr = new int[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    QuickSort s;
    s.sort(arr, n);
    s.print(arr, n);
    delete[] arr;
    return 0;
}
 */