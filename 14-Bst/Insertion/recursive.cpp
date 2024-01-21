#include <iostream>
#include <queue>
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
  if (root == NULL) {
    root = new Node(data);
    return root;
  }
  if (data > root->data) {
    root->right = insertIntoBST(root->right, data);
  } else {
    root->left = insertIntoBST(root->left, data);
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

void preOrderTraversal(Node* root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
  if (root == NULL) {
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

// Function to search for a node in the BST
int search(Node* root, int key) {
  if (root == nullptr) {
    // Node not found
    return 0;
  }

  if (root->data == key) {
    // Node found
    return 1;
  }

  if (key < root->data) {
    // Search in the left subtree
    return search(root->left, key);
  }

  // Search in the right subtree
  return search(root->right, key);
}

// Function to find the node with the minimum value in a BST
Node* findMin(Node* root) {
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

// Function to delete a node by copying in a BST
Node* deleteByCopying(Node* root, int key) {
  if (root == nullptr) {
    return root;
  }

  if (key < root->data) {
    root->left = deleteByCopying(root->left, key);
  } else if (key > root->data) {
    root->right = deleteByCopying(root->right, key);
  } else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }

    // Node with two children: Get the inorder successor (smallest
    // in the right subtree)
    Node* temp = findMin(root->right);

    // Copy the inorder successor's data to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteByCopying(root->right, temp->data);
  }
  return root;
}

// Function to delete a node by merging in a BST
Node* deleteByMerging(Node* root, int key) {
  if (root == nullptr) {
    return root;
  }

  // Search for the node to be deleted
  if (key < root->data) {
    root->left = deleteByMerging(root->left, key);
  } else if (key > root->data) {
    root->right = deleteByMerging(root->right, key);
  } else {
    // Node with only one child or no child
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }

    // Node with two children, get the inorder successor (smallest
    // in the right subtree)
    Node* successor = findMin(root->right);

    // Copy the inorder successor's data to this node
    root->data = successor->data;

    // Delete the inorder successor
    root->right = deleteByMerging(root->right, successor->data);
  }
  return root;
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(Node* root) {
  if (root == nullptr) {
    return 0;
  }

  if (root->left == nullptr && root->right == nullptr) {
    // Leaf node
    return 1;
  }

  // Recursive call to left and right subtrees
  return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count the number of non-leaf nodes in a binary tree
int countNonLeafNodes(Node* root) {
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    // Null node or leaf node
    return 0;
  }

  // Recursive call to left and right subtrees
  return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Function to perform level-by-level traversal of a binary tree
void levelOrderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* current = q.front();
    q.pop();

    cout << current->data << " ";

    if (current->left != nullptr) {
      q.push(current->left);
    }

    if (current->right != nullptr) {
      q.push(current->right);
    }
  }
}

// Function to calculate the height of a binary tree
int height(Node* root) {
  if (root == nullptr) {
    return 0;
  }

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  // Height of the tree is the maximum of left and right subtree heights, plus 1
  // for the current level
  return 1 + max(leftHeight, rightHeight);
}

int main() {
  Node* root = NULL;
  takeInput(root);

  cout << "Preorder Traversal" << endl;
  preOrderTraversal(root);
  cout << endl;

  cout << "Inorder Traversal" << endl;
  inOrderTraversal(root);
  cout << endl;

  cout << "Postorder Traversal" << endl;
  postOrderTraversal(root);
  cout << endl;

  cout << "Level-by-Level Traversal:" << endl;
  levelOrderTraversal(root);
  cout << endl;

  int leafNodes = countLeafNodes(root);
  int nonLeafNodes = countNonLeafNodes(root);

  cout << "Number of Leaf Nodes: " << leafNodes << endl;
  cout << "Number of Non-Leaf Nodes: " << nonLeafNodes << endl;

  int keyToDelete;
  cout << "Enter the key to delete: ";
  cin >> keyToDelete;

  cout << "BST before deletion:" << endl;
  preOrderTraversal(root);
  cout << endl;

  root = deleteByCopying(root, keyToDelete);

  cout << "BST after deletion:" << endl;
  preOrderTraversal(root);
  cout << endl;

  int treeHeight = height(root);
  cout << "Height of the Binary Tree: " << treeHeight << endl;

  int searchKey;
  cin >> searchKey;
  int result = search(root, searchKey);
  if (result == 1) {
    cout << "Node found!" << endl;
  } else {
    cout << "Node not found!" << endl;
  }

  return 0;
}