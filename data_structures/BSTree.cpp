#include <iostream>

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


static int count = 0;

class BSTree {
    private:
        Node* root;
        void insert(Node* &root, int data);
        void deleteNode(Node* &root, int data);
        Node* findMin(Node* root);
        void inorder(Node* root);
    public:
        BSTree();
        void insert(int data);
        void deleteNode(int data);
        bool search(int data);
        void print();
        ~BSTree();
};

BSTree::BSTree() {
    this->root = NULL;
}

void BSTree::insert(int data) {
    this->insert(this->root, data);
}

void BSTree::insert(Node* &root, int data) {
    if (root == NULL) {
        root = new Node(data);
    } else if (data <= root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void BSTree::deleteNode(int data) {
    this->deleteNode(this->root, data);
}

void BSTree::deleteNode(Node* &root, int data) {
    ++count;
    std::cout << "delete node : " << count << std::endl;
    if (root == NULL) {
        return;
    } else if (data < root->data) {
        deleteNode(root->left, data);
    } else if (data > root->data) {
        deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) { // No child
            std::cout << "No child" << std::endl;
            delete root;
            root = NULL;
        } else if (root->left == NULL) { // One child
            Node* tmp = root;
            root = root->right;
            std::cout << "One child" << std::endl;
            delete tmp;
        } else if (root->right == NULL) { // One child
            Node* tmp = root;
            root = root->left;
            std::cout << "One child" << std::endl;
            delete tmp;
        } else { // Two child

            // recursive
            // std::cout << "Two child" << std::endl;
            // Node* tmp = findMin(root->right);
            // root->data = tmp->data;
            // deleteNode(root->right, tmp->data);

            Node* successParent = root;
            Node* success = root->right;

            while (success->left != NULL) {
                successParent = success;
                success = success->left;
            }

            if (successParent != root) {
                successParent->left = success->right;
            } else {
                successParent->right = success->right;
            }

            root->data = success->data;

            delete success;
        }
    }
}

bool BSTree::search(int data) {
    Node* iterator = this->root;
    while (iterator != NULL) {
        if (iterator->data == data) {
            return true;
        } else if (data > iterator->data) {
            iterator = iterator->right;
        } else {
            iterator = iterator->left;
        }
    }
    return false;
}

Node* BSTree::findMin(Node* root) {
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

void BSTree::inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        std::cout << "data: " << root->data << std::endl;
        inorder(root->right);
    }
}

void BSTree::print() {
    this->inorder(this->root);
}

BSTree::~BSTree() {
    if (root->left == NULL && root->right == NULL) {
        delete root;
    }
}

int main() {
    BSTree mBSTree;
    mBSTree.insert(12);
    mBSTree.insert(5);
    mBSTree.insert(15);
    mBSTree.insert(3);
    mBSTree.insert(7);
    mBSTree.insert(13);
    mBSTree.insert(17);
    mBSTree.insert(1);
    mBSTree.insert(9);
    // std::cout << "Check 15: " << mBSTree.search(15) << std::endl;
    // std::cout << "Check 8: " << mBSTree.search(8) << std::endl;
    mBSTree.print();

    mBSTree.deleteNode(15);
    std::cout << "Check 15: " << mBSTree.search(15) << std::endl;

    return 0;
}
