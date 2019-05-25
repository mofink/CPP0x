//https://leetcode.com/problems/balanced-binary-tree/

/*
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
    
    struct BalancedStatusWithHeight
    {
        bool balanced;
        int height;
    };
    
    BalancedStatusWithHeight checkBalanced(TreeNode* tree)
    {
        if (tree == nullptr)
        {
            return {true, -1};
        }
        
        auto left_status = checkBalanced(tree->left);
        if (!left_status.balanced)
        {
            return {false,0};
        }
        
        auto right_status = checkBalanced(tree->right);
        if (!right_status.balanced)
        {
            return {false,0};
        }
        
        int height = std::max(left_status.height, right_status.height) + 1;
        bool balanced = std::abs(left_status.height - right_status.height) <= 1;
        return {balanced, height};
    }
    
public:
    bool isBalanced(TreeNode* root) 
    {
        return checkBalanced(root).balanced;   
    }
};
