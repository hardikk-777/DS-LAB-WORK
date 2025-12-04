


//4.
// #include <iostream>
// #include <queue>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* newNode(int v){
//     Node* n=new Node;
//     n->data=v;
//     n->left=n->right=nullptr;
//     return n;
// }

// Node* buildTree(){
//     int x;
//     cin>>x;
//     if(x==-1) return nullptr;
//     Node* root=newNode(x);
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* t=q.front();
//         q.pop();
//         cin>>x;
//         if(x!=-1){
//             t->left=newNode(x);
//             q.push(t->left);
//         }
//         cin>>x;
//         if(x!=-1){
//             t->right=newNode(x);
//             q.push(t->right);
//         }
//     }
//     return root;
// }

// bool check(Node* root,long long minv,long long maxv){
//     if(root==nullptr) return true;
//     if(root->data<=minv || root->data>=maxv) return false;
//     return check(root->left,minv,root->data) && check(root->right,root->data,maxv);
// }

// int main(){
//     Node* root=buildTree();
//     if(check(root,-1e18,1e18)) cout<<"BST";
//     else cout<<"Not BST";
//     return 0;
// }
