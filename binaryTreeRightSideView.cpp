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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        int level = -1;
        rightside(root, ans, level, 0);
        return ans;
    }

    void rightside(TreeNode *root, vector<int> &ans, int &level, int currlevel)
    {
        if (root == nullptr)
            return;
        if (currlevel > level)
        {
            level = currlevel;
            ans.push_back(root->val);
        }
        rightside(root->right, ans, level, currlevel + 1);
        rightside(root->left, ans, level, currlevel + 1);
    }
};