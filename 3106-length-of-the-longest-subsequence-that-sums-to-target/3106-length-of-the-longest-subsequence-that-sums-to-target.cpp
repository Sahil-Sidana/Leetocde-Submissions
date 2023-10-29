class Solution {
public:
    int solve(int i,int target,int &n,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0) return 0;
        if(i==n) return -1e5;
        if(dp[i][target]!=-1) return dp[i][target];
        int take=INT_MIN,nottake=0;
        nottake=solve(i+1,target,n,nums,dp);
        if(target>=nums[i]){
            take=1+solve(i+1,target-nums[i],n,nums,dp);
        }
        return dp[i][target]=max(take,nottake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=solve(0,target,n,nums,dp);
        if(ans<1 || ans>1000) return -1;
        return ans;
    }
};