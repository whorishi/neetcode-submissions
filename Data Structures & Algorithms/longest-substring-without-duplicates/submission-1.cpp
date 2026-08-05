class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=1;
        int ans=1;
        if(s.length()==0) return 0;
        unordered_map<char,int>m;
        m[s[0]]++;
        for(j=1;j<s.length();j++){
            m[s[j]]++;
            if(i<j && m[s[j]]>1 ){
                while(m[s[j]]>1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
            }else{
                ans=max(ans,int(m.size()));
            }
        }
        return ans;
    }
};
