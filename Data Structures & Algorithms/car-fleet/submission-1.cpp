class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>vp;
        for(int i=0;i<position.size();i++){
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        // reverse(vp.begin(),vp.end());
        int ans=0;
        stack<double>st;
        for(auto ele:vp){
            double t = (double)(target-ele.first)/(double)ele.second;
            if(st.empty()){
                st.push(t);
            }
            else{
                while(!st.empty() && st.top()<=t){
                    st.pop();
                }
                st.push(t);
            }
        }
        return (int)st.size();
    }
};
 
// 0 2 4      target 10
// 2 3 1

// 5 2.xyz 6

// 6





