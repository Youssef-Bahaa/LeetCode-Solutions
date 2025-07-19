class Solution {
public:
    bool small(string word){
        for(auto i : word)if(i >='A' and i <= 'Z')return false;
        return true;
    }
    bool cap(string word){
        for(auto i : word)if(i >='a' and i <= 'z')return false;
        return true;
    }
    bool detectCapitalUse(string word) {
        if (cap(word) || small(word) || 
                (word[0] >= 'A' && word[0] <= 'Z' && small(word.substr(1))))
                return true;
        

        return false;

    }
    
};