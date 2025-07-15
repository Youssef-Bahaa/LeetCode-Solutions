class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)return false;
        bool letter_digit = false;
        bool vowel = false; 
        bool consonant = false;
        
        for(int i = 0 ; i < word.size(); i++){

            char c = tolower(word[i]);

            if(isdigit(c)){letter_digit = true;continue;}

            if ((c  >= 'a' and c <= 'z'))letter_digit = true;

            else return false;
            
            if(c !='a' and c != 'e' and c != 'i' 
                and c != 'o' and c != 'u')consonant = true;
            
            else vowel = true;
        }

        return letter_digit and vowel and consonant;
    }
};