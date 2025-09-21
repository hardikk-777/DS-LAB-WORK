#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // a) Diagonal Matrix
    int *diag = new int[n];
    for(int i=0;i<n;i++) cin >> diag[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << (i==j ? diag[i] : 0) << " ";
        cout << endl;
    }

    // b) Tri-diagonal Matrix
    int *tri[n];
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1) tri[i] = new int[2];
        else tri[i] = new int[3];
    }
    for(int i=0;i<n;i++){
        int len = (i==0 || i==n-1)?2:3;
        for(int j=0;j<len;j++) cin >> tri[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<tri[i][(i==0||i==n-1)?0:1]<<" ";
            else if(j==i-1) cout<<tri[i][0]<<" ";
            else if(j==i+1) cout<<tri[i][(i==0)?1:2]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }

    // c) Lower Triangular Matrix
    int* low[n];
    for(int i=0;i<n;i++) low[i]=new int[i+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++) cin>>low[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(j<=i) cout<<low[i][j]<<" "; else cout<<"0 ";
        cout<<endl;
    }

    // d) Upper Triangular Matrix
    int* up[n];
    for(int i=0;i<n;i++) up[i]=new int[n-i];
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++) cin>>up[i][j-i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(j>=i) cout<<up[i][j-i]<<" "; else cout<<"0 ";
        cout<<endl;
    }

    // e) Symmetric Matrix
    int* sym[n];
    for(int i=0;i<n;i++) sym[i]=new int[i+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++) cin>>sym[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(j<=i) cout<<sym[i][j]<<" "; else cout<<sym[j][i]<<" ";
        cout<<endl;
    }
}
