#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* insertIntoBST(Node* root, int data) {
  Node* newNode = new Node(data);

  if (root == NULL) {
    return newNode;
  }

  Node* current = root;
  Node* parent = nullptr;

  while (current != NULL) {
    parent = current;

    if (data > current->data) {
      current = current->right;
    } else {
      current = current->left;
    }
  }

  if (data > parent->data) {
    parent->right = newNode;
  } else {
    parent->left = newNode;
  }

  return root;
}

void takeInput(Node*& root) {
  int data;
  cin >> data;

  while (data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

// Function to perform in-order traversal and swap left and right children
void mirrorImage(Node* root) {
  if (root == NULL) {
    return;
  }

  // Swap left and right children
  swap(root->left, root->right);

  // Recursive call to left and right subtrees
  mirrorImage(root->left);
  mirrorImage(root->right);
}

// Function to perform in-order traversal to print the tree
void inOrderTraversal(Node* root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

int main() {
  Node* root = NULL;
  takeInput(root);

  cout << "Original BST:" << endl;
  inOrderTraversal(root);
  cout << endl;

  // Get the mirror image of the BST
  mirrorImage(root);

  cout << "Mirror Image BST:" << endl;
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
