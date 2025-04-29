/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

 class Solution {
    public:
        typedef unsigned long long ll;
        int widthOfBinaryTree(TreeNode* root) {
            queue<pair<TreeNode*, ll>> q;
            q.push({root, 0});
    
            ll maxWidth = 1;
    
            while (!q.empty()) {
                ll levelSize = q.size();
                auto it1 = q.front();
                auto it2 = q.back();
    
                maxWidth = max(maxWidth, it2.second - it1.second + 1);
    
                // push all the neighbours of the nodes present in q and remove
                // themselves as well
                while (levelSize > 0) {
                    TreeNode* curr = q.front().first;
                    ll idx = q.front().second;
    
                    if (curr->left) {
                        q.push({curr->left, (2 * idx) + 1});
                    }
                    if (curr->right) {
                        q.push({curr->right, (2 * idx) + 2});
                    }
                    q.pop();
                    levelSize--;
                }
            }
            return maxWidth;
        }
    };