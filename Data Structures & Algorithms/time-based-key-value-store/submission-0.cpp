class TimeMap {
public:
    map<string,map<int,string>>m;
    map<string,set<int>>mset;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
        mset[key].insert(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        if(mset[key].size()==0) return "";

        if(mset[key].upper_bound(timestamp)==mset[key].begin()) return "";
        auto it = mset[key].upper_bound(timestamp);
        --it;
        // cout<<*it<<endl;
        return m[key][*it];

        return "";
    }
};
