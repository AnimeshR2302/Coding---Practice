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
private: 
    pair<int,bool> checkBal(TreeNode* &cur) {
        if(!cur) return {0,true};

        auto [ldep,lt] = checkBal(cur->left);
        if(!lt) return {ldep+1,false};
        auto [rdep, rt] = checkBal(cur->right);
        if(!rt) return {rdep+1, false};

        return {max(ldep,rdep)+1, ldep-rdep<=1 && ldep-rdep>=-1};
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        return checkBal(root).second;
    }
};