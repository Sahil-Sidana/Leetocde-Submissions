class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        int n=dist.size();
        for(int i=0;i<n;i++){
            time.push_back(dist[i]/(double)speed[i]);
        }
        int ans=1,check=1;
        sort(time.begin(),time.end());
        for(auto x:time) cout<<x<<endl;
        for(int i=1;i<n;i++){
            if(time[i]>check){
                ans++;
                check++;
            }
            else{
                break;
            }    
        }
        return ans;
    }
};