class Solution {
public:
    void check(vector<int> &nums,vector<vector<int>> &ans,int id){
        
        if(id>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=id;i<nums.size();i++){
            if(i!=id && nums[id]==nums[i]){
                continue;
            }
            swap(nums[i],nums[id]);
            check(nums,ans,id+1);
            swap(nums[i],nums[id]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        check(nums,ans,0);
        set<vector<int>>st(ans.begin(),ans.end());
        ans.clear();
        for(auto &x:st) ans.push_back(x);
        return ans;

    }
};