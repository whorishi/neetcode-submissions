class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>left(n),right(n);
        left[0]=h[0];
        right[n-1]=h[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(h[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(h[i],right[i+1]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans += max(0,min(left[i-1],right[i+1])-h[i]);
        }
        return ans;
    }
};
