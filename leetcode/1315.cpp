#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int result = 0;
        calculateParents(root, NULL, result);
        return result;
    }
    
    int sum = 0;
    void calculateParents(TreeNode *root, TreeNode *parent, int &sum) {
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(parent && parent->val %2 == 0) {
            if(root->left != NULL) {
                sum += root->left->val;
            }
            if(root->right != NULL) {
                sum += root->right->val;
            }    
        }
        
        if(root->left != NULL) {
            calculateParents(root->left, root, sum);
        }
        if(root->right != NULL) {
            calculateParents(root->right, root, sum);
        }
    }
};

int main() {
    Solution s;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(5);

    std::cout<<s.sumEvenGrandparent(root);
    return 0;
}