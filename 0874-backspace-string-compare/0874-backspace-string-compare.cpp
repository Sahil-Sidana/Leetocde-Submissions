class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1,s2;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') s1+=s[i];
            else if(s1.size()>=1) s1.pop_back();
            // else return false;
        }
        for(int i=0;i<t.size();i++){
            if(t[i]>='a' && t[i]<='z') s2+=t[i];
            else if(s2.size()>=1) s2.pop_back();
            // else return false;
        }
        return s1==s2;
    }
};