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

    int prev = 0;
    int cnt = 0;
    int maxcnt = 0;
    bool first = true;
    vector<int> ans;

    void inorder( TreeNode * root ){
        if(root == nullptr) return;

        //traverse to left subtree
        inorder(root->left);

        //freq cnt
        if (first || root->val != prev){
            cnt = 1;
            first = false;
        } else {
            cnt++;
        }

        //update ans
        if (cnt > maxcnt){
            maxcnt = cnt ;
            ans.clear();
            ans.push_back(root->val);
        } else if (cnt == maxcnt) {
            ans.push_back(root->val);
        }
        prev = root->val;
        
        //traverse right subtree
        inorder(root->right);

    }


    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};