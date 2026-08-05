class Solution {
public:

    long long calcTime(int speed, vector<int>&piles){
        long long tt=0;
        for(auto ele:piles){
            tt+= ceil((long long)(ele)/(long double)(speed));
        }
        return tt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long end = accumulate(piles.begin(),piles.end(),0LL);
        long long start=1;
        long long ans=end;
        while(start<=end){
            long long mid = start + (end-start)/2;

            if(calcTime(mid,piles)<=h){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
