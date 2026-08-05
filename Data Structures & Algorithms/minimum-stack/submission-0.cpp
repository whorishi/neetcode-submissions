class MinStack {
public:
    map<int,int>m;
    vector<int>v;
    MinStack() {

    }
    
    void push(int val) {
        v.push_back(val);
        m[val]++;
    }
    
    void pop() {
        int last = v.back();
        v.pop_back();
        m[last]--;
        if(m[last]==0) m.erase(last);
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};
