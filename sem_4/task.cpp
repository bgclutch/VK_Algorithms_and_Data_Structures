#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

#if 0
// Create a binary tree from array

namespace bintree {
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
    void destroyTree(TreeNode* root) noexcept {
        if (!root)
            return;
        if (root->left)
            destroyTree(root->left);
        if (root->right)
            destroyTree(root->right);
        delete root;
    }

    void printInorder(TreeNode* root) const noexcept {
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
    bintree::Tree MyTree{data};
    MyTree.printTree();

    return EXIT_SUCCESS;
}
#endif


namespace bst {
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value{val}, left{nullptr}, right{nullptr} {}
};

struct Tree {
    TreeNode* root = nullptr;
    Tree (const std::vector<int>& data) {
        std::vector<int> sorted_data = data;
        std::sort(sorted_data.begin(), sorted_data.end());

        if (sorted_data.empty())
            root = nullptr;
        else
            root = buildTree(sorted_data, 0, sorted_data.size() - 1);
    }

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
    TreeNode* buildTree(const std::vector<int>& data, const ssize_t start, const ssize_t end) {
        if (start > end)
            return nullptr;

        ssize_t mid = (start + end) / 2;
        TreeNode* curNode = new TreeNode(data[mid]);
        curNode->left = buildTree(data, start, mid - 1);

        curNode->right = buildTree(data, mid + 1, end);
        return curNode;
    }

 private:
    void destroyTree(TreeNode* root) noexcept {
        if (!root)
            return;
        if (root->left)
            destroyTree(root->left);
        if (root->right)
            destroyTree(root->right);
        delete root;
    }

    void printInorder(TreeNode* node) const noexcept {
        if (!node)
            return;
        printInorder(node->left);
        std::cout << node->value << " ";
        printInorder(node->right);
    }

 public:
    ssize_t getMinMaxMult() const {
        return getMinVal() * getMaxVal();
    }

    ssize_t getMinVal() const {
        if (!root)
            throw std::runtime_error("No root in tree");
        TreeNode* node = root;
        while (node->left)
            node = node->left;
        return node->value;
    }

    ssize_t getMaxVal() const {
        if (!root)
            throw std::runtime_error("No root in tree");
        TreeNode* node = root;
        while (node->right)
            node = node->right;
        return node->value;
    }
};
}

TEST(GETMULT, first) {
    std::vector<int> data {21, 19, 18, 11, 12, 15, 16, 9, 8, 10};
    size_t len = data.size();
    bst::Tree MyTree{data};
    ssize_t res = 0;
    try {
        res = MyTree.getMinMaxMult();
    } catch (std::runtime_error&) {}

    ASSERT_EQ(res, 168);
}

TEST(GETMULT, second) {
    std::vector<int> data {-10, 2, 3, 4, 190, 12, 123, 421, 42, 24};
    size_t len = data.size();
    bst::Tree MyTree{data};
    ssize_t res = 0;
    try {
        res = MyTree.getMinMaxMult();
    } catch (std::runtime_error&) {}

    ASSERT_EQ(res, -4210);
}

TEST(GETMULT, third) {
    std::vector<int> data {21, 19, 18, 11, 12, 15, 16, 9, 8, 10, -1};
    size_t len = data.size();
    bst::Tree MyTree{data};
    ssize_t res = 0;
    try {
        res = MyTree.getMinMaxMult();
    } catch (std::runtime_error&) {}

    ASSERT_EQ(res, -21);
}

TEST(GETBST, first) {
    std::vector<int> data {21, 19, 18, 11, 12, 15, 16, 9, 8, 10};
    size_t len = data.size();
    bst::Tree MyTree{data};

    ASSERT_EQ(MyTree.getMinVal(), 8);
}

TEST(GETBST, second) {
    std::vector<int> data {43, 42, 41, 40, 10, 9, 8, -100};
    size_t len = data.size();
    bst::Tree MyTree{data};

    ASSERT_EQ(MyTree.getMaxVal(), 43);
}

TEST(GETBST, third) {
    std::vector<int> data {42, 567, 42, 42, 42, 42, 87};
    size_t len = data.size();
    bst::Tree MyTree{data};

    ASSERT_NE(MyTree.getMaxVal(), 42);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#if 0
int main() {
    std::vector<int> data {21, 19, 18, 11, 12, 15, 16, 9, 8, 10};
    size_t len = data.size();
    bst::Tree MyTree{data};
    MyTree.printTree();
    try {
        std::cout << MyTree.getMinMaxMult() << std::endl;
    } catch (std::runtime_error&) {}

    return EXIT_SUCCESS;
}
#endif