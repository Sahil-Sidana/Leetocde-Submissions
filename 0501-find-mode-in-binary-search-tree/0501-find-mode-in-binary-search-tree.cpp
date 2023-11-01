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
    void solve(TreeNode *root,unordered_map<int,int> &m){
        if(root==NULL){
            return;
        }
        solve(root->left,m);
        m[root->val]++;
        solve(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>m;
        solve(root,m);
        int maxi=INT_MIN;
        vector<int>ans;
        for(auto x:m){
            maxi=max(maxi,x.second);
        }
        for(auto x:m){
            if(x.second==maxi){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};