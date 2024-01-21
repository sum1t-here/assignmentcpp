#include <iostream>
#include <stack>
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

// preorder traversal
void preOrder(Node* root) {
  stack<Node*> s;
  s.push(root);

  while (!s.empty()) {
    Node* current = s.top();
    s.pop();

    if (current != nullptr) {
      cout << current->data << " ";
      s.push(current->right);
      s.push(current->left);
    }
  }
}

// inorder traversal

void inOrderTraversal(Node* root) {
  stack<Node*> s;
  Node* current = root;

  while (current != NULL || !s.empty()) {
    while (current != NULL) {
      s.push(current);
      current = current->left;
    }

    current = s.top();
    s.pop();

    cout << current->data << " ";
    current = current->right;
  }
}

// postorder traversal
void postOrder(Node* root) {
  stack<Node*> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    Node* current = s1.top();
    s1.pop();
    s2.push(current);

    if (current->left) {
      s1.push(current->left);
    }

    if (current->right) {
      s1.push(current->right);
    }
  }

  while (!s2.empty()) {
    cout << s2.top()->data << " ";
    s2.pop();
  }
}

int main() {
  Node* root = NULL;
  takeInput(root);

  cout << "Preorder Traversal" << endl;
  preOrder(root);
  cout << endl;

  cout << "Inorder Traversal" << endl;
  inOrderTraversal(root);
  cout << endl;

  cout << "Postorder Traversal" << endl;
  postOrder(root);
  cout << endl;
  return 0;
}