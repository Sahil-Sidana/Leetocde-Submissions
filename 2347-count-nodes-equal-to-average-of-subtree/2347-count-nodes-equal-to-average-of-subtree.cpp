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

    void preorder(TreeNode *root,vector<int> &v,int &sum){
        if(root!=NULL){
            sum+=root->val;
            v.push_back(root->val);
            preorder(root->left,v,sum);
            preorder(root->right,v,sum);
        }
    }
    int avg(TreeNode *root){
        vector<int>v;
        int sum=0;
        preorder(root,v,sum);
        return sum/v.size();
    }
    
    void solve(TreeNode *root,int &ans){
        if(root==NULL){
            return;
        }
        if((root!=NULL && root->val==avg(root))||(root!=NULL && root->left==NULL && root->right==NULL)){
            ans++;
        }
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};