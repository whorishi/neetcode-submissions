class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a = nums[i];
            int target = -1*a;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>target) k--;
                else j++;
            }
        }
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};
