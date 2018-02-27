/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty()) return nullptr;
        TreeNode *node = new TreeNode(pre[0]);
        auto inPos = find(vin.begin(), vin.end(), pre[0]);
        vector<int> leftVin = vector<int>(vin.begin(), inPos);
        vector<int> rightVin = vector<int>(inPos+1, vin.end());
        vector<int> leftPre = vector<int>(pre.begin()+1, pre.begin()+leftVin.size()+1);
        vector<int> rightPre = vector<int>(pre.begin()+leftVin.size()+1, pre.end());
        node->left = reConstructBinaryTree(leftPre, leftVin);
        node->right = reConstructBinaryTree(rightPre, rightVin);
        return node;
    }
    
};