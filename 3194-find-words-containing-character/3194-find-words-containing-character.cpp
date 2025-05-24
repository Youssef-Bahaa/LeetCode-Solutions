class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            bool Enter=1;
            for(int j=0;j<s.size() and Enter;j++){
               if(s[j]==x){
                idx.push_back(i);
                Enter=0;
               }
            }
        }
        return idx;
    }
};