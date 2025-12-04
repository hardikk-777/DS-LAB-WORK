//5.
// #include <iostream>
// using namespace std;

// void heapify(int a[],int n,int i,bool inc){
//     int p=i;
//     int l=2*i+1;
//     int r=2*i+2;
//     if(inc){
//         if(l<n && a[l]>a[p]) p=l;
//         if(r<n && a[r]>a[p]) p=r;
//     }else{
//         if(l<n && a[l]<a[p]) p=l;
//         if(r<n && a[r]<a[p]) p=r;
//     }
//     if(p!=i){
//         int t=a[p];
//         a[p]=a[i];
//         a[i]=t;
//         heapify(a,n,p,inc);
//     }
// }

// void heapsort(int a[],int n,bool inc){
//     for(int i=n/2-1;i>=0;i--) heapify(a,n,i,inc);
//     for(int i=n-1;i>=0;i--){
//         int t=a[0];
//         a[0]=a[i];
//         a[i]=t;
//         heapify(a,i,0,inc);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     int c;
//     cin>>c;
//     bool inc=(c==1);
//     heapsort(a,n,inc);
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     return 0;
// }


//6.
// #include <iostream>
// using namespace std;

// void heapify(int a[],int n,int i){
//     int p=i,l=2*i+1,r=2*i+2;
//     if(l<n && a[l]>a[p]) p=l;
//     if(r<n && a[r]>a[p]) p=r;
//     if(p!=i){
//         int t=a[p]; a[p]=a[i]; a[i]=t;
//         heapify(a,n,p);
//     }
// }

// void insertPQ(int a[],int& n,int v){
//     a[n]=v;
//     int i=n;
//     n++;
//     while(i>0){
//         int p=(i-1)/2;
//         if(a[p]<a[i]){
//             int t=a[p]; a[p]=a[i]; a[i]=t;
//             i=p;
//         } else break;
//     }
// }

// int deleteMax(int a[],int& n){
//     if(n==0) return -1;
//     int mx=a[0];
//     a[0]=a[n-1];
//     n--;
//     heapify(a,n,0);
//     return mx;
// }

// void display(int a[],int n){
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     cout<<endl;
// }

// int main(){
//     int a[100],n=0,ch,v;
//     while(true){
//         cin>>ch;
//         if(ch==1){cin>>v; insertPQ(a,n,v);}
//         else if(ch==2){cout<<deleteMax(a,n)<<endl;}
//         else if(ch==3){display(a,n);}
//         else if(ch==4) break;
//     }
//     return 0;
// }