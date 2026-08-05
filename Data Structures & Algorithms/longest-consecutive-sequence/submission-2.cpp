class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int temp=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                temp++;
                ans=max(ans,temp);
            }else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                temp=1;
            }
        }
        return ans;
    }
};
