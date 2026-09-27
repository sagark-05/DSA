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

    void dfs(TreeNode* node , int depth , long long index , 
            vector<long long>& leftindex ,long long& ans){
                //width = last index - first index + 1

                if(node == nullptr) return;

                if(depth == (int)leftindex.size()){
                    leftindex.push_back(index);
                }
                ans = max(ans , index - leftindex[depth] + 1);
                long long curr = index - leftindex[depth];

                dfs(node->left , depth + 1 , 2 * curr + 1  , leftindex , ans);
                dfs(node->right ,depth + 1 , 2 * curr + 2 , leftindex , ans);
            }


    int widthOfBinaryTree(TreeNode* root) {
        vector<long long> leftindex;
        long long ans = 0;
        dfs(root , 0 , 0, leftindex , ans);
        return (int)ans;
    }
};