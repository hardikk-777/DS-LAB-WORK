//3.
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(int v) {
//     Node* n = new Node;
//     n->data = v;
//     n->left = n->right = nullptr;
//     return n;
// }

// Node* insert(Node* root, int v) {
//     if (root == nullptr) return createNode(v);
//     if (v < root->data) root->left = insert(root->left, v);
//     else if (v > root->data) root->right = insert(root->right, v);
//     return root;
// }

// Node* findMin(Node* root) {
//     while (root->left != nullptr) root = root->left;
//     return root;
// }

// Node* deleteNode(Node* root, int v) {
//     if (root == nullptr) return root;
//     if (v < root->data) root->left = deleteNode(root->left, v);
//     else if (v > root->data) root->right = deleteNode(root->right, v);
//     else {
//         if (root->left == nullptr) {
//             Node* t = root->right;
//             delete root;
//             return t;
//         }
//         else if (root->right == nullptr) {
//             Node* t = root->left;
//             delete root;
//             return t;
//         }
//         Node* t = findMin(root->right);
//         root->data = t->data;
//         root->right = deleteNode(root->right, t->data);
//     }
//     return root;
// }

// int maxDepth(Node* root) {
//     if (root == nullptr) return 0;
//     int l = maxDepth(root->left);
//     int r = maxDepth(root->right);
//     return (l > r ? l : r) + 1;
// }

// int minDepth(Node* root) {
//     if (root == nullptr) return 0;
//     int l = minDepth(root->left);
//     int r = minDepth(root->right);
//     if (l == 0 || r == 0) return l + r + 1;
//     return (l < r ? l : r) + 1;
// }

// void inorder(Node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main() {
//     Node* root = nullptr;
//     int choice, value;

//     while (true) {
//         cin >> choice;
//         if (choice == 1) {
//             cin >> value;
//             root = insert(root, value);
//         }
//         else if (choice == 2) {
//             cin >> value;
//             root = deleteNode(root, value);
//         }
//         else if (choice == 3) {
//             cout << maxDepth(root) << endl;
//         }
//         else if (choice == 4) {
//             cout << minDepth(root) << endl;
//         }
//         else if (choice == 5) {
//             inorder(root);
//             cout << endl;
//         }
//         else if (choice == 0) break;
//     }

//     return 0;
// }