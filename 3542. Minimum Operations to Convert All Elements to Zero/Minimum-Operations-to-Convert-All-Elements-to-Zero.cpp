class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int cnt = 0;
        for(auto i:nums){
            while(st.size() and st.top() >i){
                st.pop();
            }
           if(i > 0 && (st.empty() || i > st.top())){
                cnt++;
                st.push(i);
            }
        }

        return cnt;

    }
};