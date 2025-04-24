Preorder

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
    class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        arr.push_back(root->val);

        preorder(root->left, arr);

        preorder(root->right, arr);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == nullptr)
        {
            return preorder;
        }
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);

            if (root->right)
            {
                st.push(root->right);
            }
            if (root->left)
            {
                st.push(root->left);
            }
        }
        return preorder;
    }
};

Inorder :-

void inorder(TreeNode *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, arr);  // L
    arr.push_back(root->val);  // N
    inorder(root->right, arr); // R
}
Postorder
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
        void postorder(TreeNode* root, vector<int>& arr) {
            if (root == nullptr) {
                return;
            }
            postorder(root->left, arr);
            postorder(root->right, arr);
            arr.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> arr;
    
            postorder(root, arr);
            return arr;
        }
    };