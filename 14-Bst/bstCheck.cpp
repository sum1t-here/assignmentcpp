#include <iostream>
#include <vector>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int d) {
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
  }
};

Node* insertIntoBST(Node* root, int data) {
  Node* newNode = new Node(data);

  if (root == NULL) {
    return newNode;
  }

  Node* current = root;
  Node* parent = nullptr;

  while (current != nullptr) {
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

// Function to perform in-order traversal and store elements in a vector
void inOrderTraversal(Node* root, vector<int>& elements) {
  if (root == nullptr) {
    return;
  }

  inOrderTraversal(root->left, elements);
  elements.push_back(root->data);
  inOrderTraversal(root->right, elements);
}

// Function to check whether two BSTs are equal or not
bool areEqualBSTs(Node* root1, Node* root2) {
  vector<int> elements1, elements2;

  // Perform in-order traversal on both BSTs and store elements in vectors
  inOrderTraversal(root1, elements1);
  inOrderTraversal(root2, elements2);

  // Compare the vectors
  return elements1 == elements2;
}

int main() {
  Node* root1 = nullptr;
  Node* root2 = nullptr;

  takeInput(root1);
  takeInput(root2);

  // Check whether the BSTs are equal
  if (areEqualBSTs(root1, root2)) {
    cout << "The two BSTs are equal." << endl;
  } else {
    cout << "The two BSTs are not equal." << endl;
  }

  return 0;
}
