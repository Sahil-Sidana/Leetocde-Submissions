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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            vector<int>v=level;
            unordered_map<int,int>m;
            for(int i=0;i<level.size();i++) m[level[i]]=i;
            sort(v.begin(),v.end());
            for(int i=0;i<level.size();i++){
                if(v[i]!=level[i]){
                    level[m[v[i]]]=level[i];
                    swap(m[level[i]],m[v[i]]);
                    level[i]=v[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};
