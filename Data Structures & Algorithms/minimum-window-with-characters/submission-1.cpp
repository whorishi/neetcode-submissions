class Solution {
public:
    bool is_t_in_substr(unordered_map<char,int>&smap,unordered_map<char,int>&tmap ){
        for(auto ele:tmap){
            int ch = ele.first;
            int freq = ele.second;
            if(smap[ch]<freq){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int>smap,tmap;
        for(int i=0;i<t.length();i++) tmap[t[i]]++;

        pair<int,int>p={-1,-1};
        int mini=INT_MAX;
        int i=0,j=0;
        while(i<=j && j<s.length()){
            smap[s[j]]++;
            j++;
            // cout<<i<<" "<<j<<endl;
            while(is_t_in_substr(smap,tmap)){
                if(j-i<=mini){
                    mini=j-i;
                    p={i,j};
                }
                smap[s[i]]--;
                i++;
            }
        }
        if(mini==INT_MAX) return "";
        string st = s.substr(p.first,p.second-p.first);
        return st;

    }
};
