class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<=n){
                int ele=nums[i];
                int pos=ele-1;
                if(nums[pos]!=ele){
                    swap(nums[pos],nums[i]);
                    i--;
                }
            }
        }
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return ans;
    }
};