class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int num = 0;
        while(s[i] == ' ')i--;
        while(i >= 0){
            if(s[i] == ' ')break;
            num++;
            i--;
        }
        return num;
    }
};