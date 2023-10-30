class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int ans=0,sum=0;
        for(auto x:m){
            sum+=x.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */