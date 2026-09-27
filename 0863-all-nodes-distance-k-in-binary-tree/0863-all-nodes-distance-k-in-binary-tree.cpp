/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parents(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent_mark){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            if(curr->left){
                parent_mark[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                parent_mark[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_mark ;
        mark_parents(root , parent_mark);

        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_dist = 0;

        while(!q.empty()){
            int size = q.size();
            if(curr_dist++ == k) break;

            for(int i=0; i< size ; i++){
                auto curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if(parent_mark[curr] && !visited[parent_mark[curr]]){
                    q.push(parent_mark[curr]);
                    visited[parent_mark[curr]] = true;
                }

            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }

        return ans;
    }
};