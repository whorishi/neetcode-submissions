class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int>m;
        for(auto ele:nums){
            m[ele]++;
        }

        for(auto ele:m){
            if(pq.size()==k){
                if(pq.top().first<ele.second){
                    pq.pop();
                    pq.push({ele.second,ele.first});
                }
            }else{
                pq.push({ele.second,ele.first});
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
