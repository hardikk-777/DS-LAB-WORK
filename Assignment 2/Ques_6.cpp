#include <iostream>
using namespace std;

class SparseMatrix {
    struct Triplet {
        int row, col, val;
    };
    Triplet data[100];
    int rows, cols, num;

public:
    void read(int r, int c, int n) {
        rows = r; cols = c; num = n;
        for(int i = 0; i < n; i++) cin >> data[i].row >> data[i].col >> data[i].val;
    }

    void display() {
        int k = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(k < num && data[k].row == i && data[k].col == j) {
                    cout << data[k++].val << " ";
                } else cout << "0 ";
            }
            cout << endl;
        }
    }

    SparseMatrix transpose() {
        SparseMatrix t;
        t.rows = cols; t.cols = rows; t.num = num;
        for(int i = 0; i < num; i++) {
            t.data[i].row = data[i].col;
            t.data[i].col = data[i].row;
            t.data[i].val = data[i].val;
        }
        return t;
    }

    SparseMatrix add(SparseMatrix &b) {
        SparseMatrix c;
        c.rows = rows; c.cols = cols;
        int i = 0, j = 0, k = 0;

        while(i < num && j < b.num) {
            if(data[i].row < b.data[j].row || 
              (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                c.data[k++] = data[i++];
            } else if(data[i].row == b.data[j].row && data[i].col == b.data[j].col) {
                c.data[k] = data[i];
                c.data[k++].val = data[i++].val + b.data[j++].val;
            } else {
                c.data[k++] = b.data[j++];
            }
        }
        while(i < num) c.data[k++] = data[i++];
        while(j < b.num) c.data[k++] = b.data[j++];
        c.num = k;
        return c;
    }

    SparseMatrix multiply(SparseMatrix &b) {
        SparseMatrix c;
        c.rows = rows; c.cols = b.cols; c.num = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < b.cols; j++) {
                int sum = 0;
                for(int x = 0; x < num; x++) {
                    if(data[x].row == i) {
                        for(int y = 0; y < b.num; y++) {
                            if(b.data[y].row == data[x].col && b.data[y].col == j) {
                                sum += data[x].val * b.data[y].val;
                            }
                        }
                    }
                }
                if(sum != 0) {
                    c.data[c.num].row = i;
                    c.data[c.num].col = j;
                    c.data[c.num].val = sum;
                    c.num++;
                }
            }
        }
        return c;
    }
};

int main() {
    SparseMatrix A, B;
    int r1, c1, n1, r2, c2, n2;

    cin >> r1 >> c1 >> n1;
    A.read(r1, c1, n1);

    cin >> r2 >> c2 >> n2;
    B.read(r2, c2, n2);

    cout << "Matrix A:" << endl; A.display();
    cout << "Matrix B:" << endl; B.display();

    cout << "Transpose of A:" << endl;
    SparseMatrix T = A.transpose(); T.display();

    cout << "A + B:" << endl;
    SparseMatrix S = A.add(B); S.display();

    if(c1 == r2) {
        cout << "A * B:" << endl;
        SparseMatrix M = A.multiply(B); M.display();
    }
}
