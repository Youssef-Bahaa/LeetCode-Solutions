class Solution {
public:
    bool isValid(string word) {
        bool minimum = word.size() >= 3;
        bool digit = false;
        bool letter = false;
        bool vowel = false; 
        bool consonant = false;
        
        for(int i = 0 ; i < word.size(); i++){

            char c = tolower(word[i]);

            if(isdigit(c)){digit = true;continue;}

            if(c  >= 'a' and c <= 'z')letter = true;

            else return false;
            
            if(c !='a' and c != 'e' and c != 'i' 
                and c != 'o' and c != 'u')consonant = true;
            
            else vowel = true;
        }

        cout << "min " << minimum <<endl;
        cout << "digit " << digit <<endl;
        cout << "letter " << letter <<endl;
        cout << "vowel " << vowel <<endl;
        cout << "consonant " << consonant <<endl;
        return minimum  and letter and vowel and consonant;
    }
};