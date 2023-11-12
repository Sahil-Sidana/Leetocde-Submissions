class Solution {
public:
    int solve(int i,vector<int> &arr,int &n,vector<int> &dp){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e4;
        for(int j=1;j<=min(arr[i],n-1-i);j++){
            if(i+j!=n-1 && arr[i+j]==0) continue;
            ans=min(ans,1+solve(i+j,arr,n,dp));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n-1,-1);
        int ans = solve(0,nums,n,dp);
        // if(ans<0 || ans==INT_MAX) return -1;
        return ans;
    }
};