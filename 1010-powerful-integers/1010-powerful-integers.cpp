class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>v1,v2;
        int i=0;
        while(pow(x,i)<=bound){
            if(x==1){
                v1.push_back(1);
                break;
            }
            v1.push_back(pow(x,i));
            i++;
        }
        i=0;
        while(pow(y,i)<=bound){
            if(y==1){
                v2.push_back(1);
                break;
            }
            v2.push_back(pow(y,i));
            i++;
        }
        vector<int>ans;
        unordered_set<int>st;
        for(auto x:v1){
            for(auto y:v2){
                if(x+y<=bound){
                    st.insert(x+y);
                }
            }
        }
        for(auto x:st) ans.push_back(x);
        return ans;
    }
};