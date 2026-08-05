class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto ele: strs ){
            s+=ele;
            s+="!)2(3*)";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>vs;
        int last=0;
        for(int i=0;i+2<s.length();i++){
            if(s.substr(i,7)=="!)2(3*)"){
                string y = s.substr(last,i-last);
                last=i+7;
                vs.push_back(y);
            }
        }
        return vs;
    }
};
