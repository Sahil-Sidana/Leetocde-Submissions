class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int m=target.size(),i=0;
        stack<int>st;
        for(int j=1;j<=n;j++){
            if(i>=m) break;
            st.push(j);
            ans.push_back("Push");
            if(!st.empty() && st.top()!=target[i]){
                st.pop();
                ans.push_back("Pop");
            }
            if(!st.empty() && st.top()==target[i]) i++;
        }
        return ans;
    }
};