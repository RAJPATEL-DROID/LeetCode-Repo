class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
            || c == 'o' || c == 'O' || c == 'u' || c == 'U')return true;
        return false;
    }
    string sortVowels(string s) {
        string vowel="";
        for(auto c : s){
            if(isVowel(c)){
                vowel += c;
            }
        }

        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0; i< s.length(); i++){
            if(isVowel(s[i])){
                s[i] = vowel[j++];   
            }
        }

        return s;
     }
};