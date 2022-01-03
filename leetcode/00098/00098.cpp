// 4ms - 98.41%
// 21.1MB - 64.14%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int array[10001] = {0};

    void In(TreeNode* root) {
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr) {
            array[cnt++] = root->val;
            return;
        }
        if(root->left) In(root->left);
        array[cnt++] = root->val;
        if(root->right) In(root->right);
    }

    bool isValidBST(TreeNode* root) {
        In(root);
        // cout << array[0] << endl;
        for(int i = 1; i < cnt; i++) {
            // cout << array[i] << endl;
            if(array[i-1] >= array[i]) return false;
        }
        return true;
        
    }
};