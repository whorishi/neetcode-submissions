class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto ele:tokens){
            if(ele=="+" || ele=="-" || ele=="*" || ele=="/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(ele=="+"){
                    st.push(b+a);
                }
                if(ele=="-"){
                    st.push(b-a);
                }
                if(ele=="*"){
                    st.push(b*a);
                }
                if(ele=="/"){
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(ele));
            }
        }
        return st.top();
    }
};
