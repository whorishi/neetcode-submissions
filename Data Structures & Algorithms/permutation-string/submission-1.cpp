class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>s1map(26,0),s2map(26,0);
        for(auto ele:s1){
            s1map[ele-97]++;
        }

        for(int i=0;i<s1.length();i++){
            s2map[s2[i]-97]++;
        }
        if(s1map==s2map) return true;
        int i=0,j=s1.length();
        
        while(j<s2.length()){
            s2map[s2[j]-97]++;
            j++;
            s2map[s2[i]-97]--;
            i++;
            if(s1map==s2map) return true;
        }
        return false;
    }
};
