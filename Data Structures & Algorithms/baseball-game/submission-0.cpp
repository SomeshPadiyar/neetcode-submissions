class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto v: operations){
            if(v=="+"){
                int x= st.top();
                st.pop();
                int y = x + st.top();
                st.push(x);
                st.push(y);
            }else if(v=="D"){
                st.push(st.top()*2);
            }else if(v=="C"){
                st.pop();
            }else{
                st.push(stoi(v));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};