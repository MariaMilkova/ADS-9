// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, const T&);
    int heightTree(Node*);
    int searchNode(Node*, const T&);

 public:
    BST() {
        root = nullptr;
    }
    void add(const T&);
    int depth();
    int search(const T&);
};

template <typename T>
typename BST<T>::Node* BST<T>:: addNode(Node* root, const T& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}

template<typename T>
inline int BST<T>::heightTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);
        if (leftHeight >= rightHeight) {
            return leftHeight + 1;
        }
        return rightHeight + 1;
    }
}

template<typename T>
inline int BST<T>::searchNode(Node* root, const T& value) {
    if (root == nullptr) {
        return -1;
    } else if (root->value == value) {
        return root->count;
    } else if (root->value > value) {
        return searchNode(root->left, value);
    } else if (root->value < value) {
        return searchNode(root->right, value);
    }
    return -1;
}

template <typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template<typename T>
inline int BST<T>::depth() {
    return heightTree(root) - 1;
}

template<typename T>
inline int BST<T>::search(const T& value) {
    return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
