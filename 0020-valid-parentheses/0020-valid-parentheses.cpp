class Solution {
public:
    char r(char x){
        if(x==')')return '(';
        else if(x==']')
            return '[';
        return '{';
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')st.push(s[i]);
 
            else if(s[i]==')' or s[i]==']' or s[i]=='}'){
                if(st.empty() or st.top()!=r(s[i]))return 0;
                st.pop();
            }
        }
        if(st.empty())return 1;
        return 0;
    }
};