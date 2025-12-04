// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int value) {
//         data = value;
//         left = right = nullptr;
//     }
// };
// Node* insert(Node* root, int value) {
//     if (root == nullptr)
//         return new Node(value);
//     if (value < root->data)
//         root->left = insert(root->left, value);
//     else if (value > root->data)
//         root->right = insert(root->right, value);
//     return root;
// }
// Node* findMin(Node* root) {
//     while (root && root->left != nullptr)
//         root = root->left;
//     return root;
// }
// Node* findMax(Node* root) {
//     while (root && root->right != nullptr)
//         root = root->right;
//     return root;
// }
// void PS(Node* root, int key, Node*& predecessor, Node*& successor) {
//     if (root == nullptr)
//         return;
//     if (root->data == key) {
//         if (root->left)
//             predecessor = findMax(root->left);
//         if (root->right)
//             successor = findMin(root->right);
//         return;
//     }
//     if (key < root->data) {
//         successor = root;
//         PS(root->left, key, predecessor, successor);
//     } else {
//         predecessor = root;
//         PS(root->right, key, predecessor, successor);
//     }
// }
// int main(){
//     Node*root=nullptr;
//     int el[]={10,40,60,80,30,20};
//     for(int i=0;i<6;i++){
//         root=insert(root,el[i]);
//     }
//     int key;
//     cout<<"enter the element : ";
//     cin>>key;
//     Node*pre=NULL;
//     Node*suc=NULL;
//     PS(root,key,pre,suc);
//     if (pre) cout << "Predecessor: " << pre->data << endl;
//     else cout << "No predecessor\n";
//     if (suc) cout << "Successor: " << suc->data << endl;
//     else cout << "No successor\n";
//     return 0;
// }
