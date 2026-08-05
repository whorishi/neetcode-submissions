class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>nse(h.size(),n);
        vector<int>pse(h.size(),-1);
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && h[st.top()]>h[i]){
                    nse[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && h[st.top()]>h[i]){
                    pse[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }

        for(int i=0;i<n;i++){
            ans = max(ans, h[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};






