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

    TreeNode* inordersuccesor(TreeNode* root ){
        root = root->right;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(key < root->val){
            root->left = deleteNode(root->left , key);
        } 
        else if (key > root->val){
            root->right = deleteNode(root->right , key);
        } 
        else {

            //0 or 1 child 
            if(root->left == nullptr){
                return root->right;
            }

            if(root->right == nullptr){
                return root->left;
            }

            //2 children 
            auto successor = inordersuccesor(root);
            root->val = successor->val;
            root->right = deleteNode(root->right , successor->val);
        }

        return root;
        
    }
};