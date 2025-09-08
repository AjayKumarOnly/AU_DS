#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* root = NULL;

Node* insert(Node* node, int val) {
    if (node == NULL) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = insert(node->left, val);
    } else if (val > node->data) {
        node->right = insert(node->right, val);
    }
    return node;
}

Node* findMin(Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                preorder(root);
                cout << endl;
                break;
            case 5:
                postorder(root);
                cout << endl;
                break;
            case 6:
                return 0;
        }
    }
}
