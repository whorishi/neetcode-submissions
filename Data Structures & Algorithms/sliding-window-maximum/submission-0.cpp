class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
        }
        vector<int>res;
        res.push_back(m.rbegin()->first);
        int j=k;
        int i=0;
        while(j<nums.size()){
            m[nums[j]]++;
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            j++;
            res.push_back(m.rbegin()->first);
        }
        return res;
    }
};
