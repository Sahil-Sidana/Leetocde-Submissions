class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long xme=abs(sx-fx);
        long long yme=abs(sy-fy);
        if(xme>t || yme>t) return 0;
        if(xme==0 && yme==0 && t==1) return 0;
        return 1;
    }
};