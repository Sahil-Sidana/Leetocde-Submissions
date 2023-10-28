#define mod (int)(1e9+7)
class Solution {
public:
    int solve(int i,int &n,char prev,vector<char> &v,vector<vector<int>> &dp){
        if(i==n) return 1;
        int idx=-1;
        if(prev=='a') idx=0;
        if(prev=='e') idx=1;
        if(prev=='i') idx=2;
        if(prev=='o') idx=3;
        if(prev=='u') idx=4;
        if(prev=='b') idx=5;
        if(dp[i][idx]!=-1) return dp[i][idx];
        int temp=0;
        if(prev=='b'){
            for(auto x:v){
                temp=(temp%mod+solve(i+1,n,x,v,dp)%mod)%mod;
            }
        }
        if(prev=='a'){
            temp=(temp%mod+solve(i+1,n,'e',v,dp)%mod)%mod;
        }
        if(prev=='e'){
            temp=(temp%mod+solve(i+1,n,'a',v,dp)%mod)%mod;
            temp=(temp%mod+solve(i+1,n,'i',v,dp)%mod)%mod;
        }
        if(prev=='i'){
           for(auto x:v){
                if(x!='i') temp=(temp%mod+solve(i+1,n,x,v,dp)%mod)%mod;
            }  
        }
        if(prev=='o'){
            temp=(temp%mod+solve(i+1,n,'i',v,dp)%mod)%mod;
            temp=(temp%mod+solve(i+1,n,'u',v,dp)%mod)%mod;
        }
        if(prev=='u'){
            temp=(temp%mod+solve(i+1,n,'a',v,dp)%mod)%mod;
        }
        return dp[i][idx]=temp;
    }
    int countVowelPermutation(int n) {
        vector<char>v{'a','e','i','o','u'};
        vector<vector<int>>dp(n,vector<int>(6,-1));
        return solve(0,n,'b',v,dp);
    }
};