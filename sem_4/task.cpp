#include <iostream>
#include <vector>

namespace bst {
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value{val}, left{nullptr}, right{nullptr} {}
};

struct Tree {
    TreeNode* root = nullptr;
    Tree (const std::vector<int>& data) : root{buildTree(data, 0, data.size())} {}
    ~Tree() {
        destroyTree(root);
    }

    Tree (const Tree& other) = delete;
    Tree (const Tree&& other) = delete;
    Tree& operator=(Tree& other) = delete;
    Tree& operator=(Tree&& other) = delete;

    void printTree()const {
        printInorder(root);
        std::cout << std::endl;
    }

 private:
    TreeNode* buildTree(const std::vector<int>& data, size_t i, const size_t len) {
        if (i >= len)
            return nullptr;

        TreeNode* curNode = new TreeNode(data[i]);
        curNode->left  = buildTree(data, 2 * i + 1, len);
        curNode->right = buildTree(data, 2 * i + 2, len);
        return curNode;
    }

 private:
    void destroyTree(TreeNode* root) {
        if (!root)
            return;
        if (root->left)
            destroyTree(root->left);
        if (root->right)
            destroyTree(root->right);
        delete root;
    }

    void printInorder(TreeNode* root) const {
        if (!root)
            return;
        printInorder(root->left);
        std::cout << root->value << " ";
        printInorder(root->right);
    }
};
}


int main() {
    std::vector<int> data {21, 19, 18, 11, 12, 15, 16, 9, 8, 10};
    size_t len = data.size();
    bst::Tree MyTree{data};
    MyTree.printTree(ё);

    return EXIT_SUCCESS;
}