#include <stack>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* min = st.top();
        st.pop();
        if(min->right) pushLeftNodes(min->right);
        return min->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
    
    void pushLeftNodes(TreeNode* root) {
        
        if(!root) return;
        st.push(root);
        pushLeftNodes(root->left);
        
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();

    std::cout<<param_1<<"\n";
    std::cout<<param_2<<"\n";

    return 0;
}