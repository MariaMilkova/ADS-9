// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BSTree {
 private:
    struct Node {
        T value;
        int count;
        int depth;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, const T&);
    int heightTree(Node*);
    int searchNode(Node*, const T&);

 public:
    BSTree() {
        root = nullptr;
    }
    void add(const T&);
    int height();
    int search(const T&);
};

template <typename T>
typename BSTree<T>::Node* BSTree<T>:: addNode(Node* root, const T& value) {
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
inline int BSTree<T>::heightTree(Node*) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);
        if (leftHeight >= rightHeight) {
            return leftHeight;
        }
        return rightHeight;
    }
}

template<typename T>
inline int BSTree<T>::searchNode(Node* root, const T& value) {
    if (root == nullptr) {
        return -1;
    } else if (root->value == value) {
        return root->count;
    } else if (root->value > value) {
        return searchNode(root->left, value);
    } else if (root->value < value) {
        return searchNode(root->right, value);
    }
}

template <typename T>
void BSTree<T>::add(const T& value) {
    root = addNode(root, value);
}

template<typename T>
inline int BSTree<T>::height() {
    return heightTree(root);
}

template<typename T>
inline int BSTree<T>::search(const T& value) {
    return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
