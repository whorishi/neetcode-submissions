class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto ele:strs){
            string s = ele;
            sort(s.begin(),s.end());
            m[s].push_back(ele);
        }

        vector<vector<string>>ans;
        for(auto ele:m){
            ans.push_back(ele.second);
        }
        return ans;
    }
};
