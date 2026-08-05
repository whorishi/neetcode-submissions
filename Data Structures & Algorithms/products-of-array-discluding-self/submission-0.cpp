class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=nums[i]*left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=nums[i]*right[i+1];
        }

        vector<int>res;
        for(int i=0;i<n;i++){
            if(i==0){
                res.push_back(right[i+1]);
            }
            else if(i==n-1){
                res.push_back(left[i-1]);
            }
            else{
                res.push_back(right[i+1]*left[i-1]);
            }
        }

        return res;

    }
};
