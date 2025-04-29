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
    private:
        void markParents(TreeNode* root,
                         unordered_map<TreeNode*, TreeNode*>& parent_track) {
            queue<TreeNode*> q;
            q.push(root);
    
            while (!q.empty()) {
                auto it = q.front();
                q.pop();
    
                if (it->left) {
                    q.push(it->left);
                    parent_track[it->left] = it;
                }
                if (it->right) {
                    q.push(it->right);
                    parent_track[it->right] = it;
                }
            }
        }
    
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            // step 1 - Mark parents
            unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
            markParents(root, parent_track);
    
            // step 2  - second bfs to find nodes at distance k
            queue<TreeNode*> q;
            unordered_map<TreeNode*, bool> visited;
            q.push(target);
            visited[target] = true;
            int currLevel = 0;
    
            while (!q.empty()) {
                int size = q.size();
                if (currLevel++ == k)
                    break;
    
                for (int i = 0; i < size; i++) {
                    TreeNode* curr = q.front();
                    q.pop();
    
                    // push left if it exists
                    if (curr->left != nullptr && !visited[curr->left]) {
                        q.push(curr->left);
                        visited[curr->left] = true;
                    }
                    // push if right exists
                    if (curr->right != nullptr && !visited[curr->right]) {
                        q.push(curr->right);
                        visited[curr->right] = true;
                    }
                    // push the upward node
                    if (parent_track[curr] && !visited[parent_track[curr]]) {
                        q.push(parent_track[curr]);
                        visited[parent_track[curr]] = true;
                    }
                }
            }
            // step 3 push all queue elements in ans vector
            vector<int> ans;
            while (!q.empty()) {
                TreeNode* current = q.front();
                q.pop();
                ans.push_back(current->val);
            }
            return ans;
        }
    };