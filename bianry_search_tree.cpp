
#include <iostream>
using namespace std;
#define null 0

template <typename T>
class Tree;

template <typename T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null){
        this->data = data;
        this->left = left;
        this->right = right;


        }
     friend ostream& operator<<(ostream& os, const TreeNode<T>& node) {
            os << "[data] " << node.data << endl;
            if (node.left != null) {
                os << "[left] " << node.left->data << endl;
            }
            if (node.right != null) {
                os << "[right] " << node.right->data << endl;
            }
            return os;
      }
    
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
public:
    Tree(T data = 0) {
        root = new TreeNode<T>(data);
    }
    void buildSearchTree() {
        insertNode(new TreeNode<int>(3));
        insertNode(new TreeNode<int>(10));
        insertNode(new TreeNode<int>(14));
        insertNode(new TreeNode<int>(2));
        insertNode(new TreeNode<int>(5));
        insertNode(new TreeNode<int>(11));
        insertNode(new TreeNode<int>(16));
    }
    void insertNode(TreeNode<T>* node) {
        if (search(root, node->data) == null) {
            TreeNode<T>* parent = null;
            TreeNode<T>* current = root;
            while (current != null) {
                parent = current;
                if (node->data < parent->data) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
            if (node->data < parent->data) {
                parent->left = node;
            }
            else {
                parent->right = node;
            }
            cout << "Inserted " << node->data << endl;
        }
    }

    TreeNode<T>* getRoot() {
        return root;
    }
    void preorder(TreeNode<T>* current) {
        if (current != null) {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }
    void visit(TreeNode<T>* current) {
        cout << current->data << " ";
    }
    TreeNode<T>* search(TreeNode<T>* current, T data) {
        if (current == null)return null;
        if (data == current->data) {
            return current;
        }
        else if (data < current->data) {
            search(current->left, data);
        }
        else {
            search(current->right, data);
        }
    }
};

int main()
{
    Tree<int> tree(8);
    tree.buildSearchTree();
    cout << "preorder>> ";
    tree.preorder(tree.getRoot());
    cout << endl;

    tree.insertNode(new TreeNode<int>(4));
    cout << "Preorder >>";
    tree.preorder(tree.getRoot());
    cout << endl;

    int number;
    cout << "input number to search>> ";
    cin >> number;

    TreeNode<int>* found = tree.search(tree.getRoot(), number);

    if (found != null) {
        cout << "Found node." << endl;
        cout << found;
    }
    else {
        cout << "Not found node." << endl;
    }
}

