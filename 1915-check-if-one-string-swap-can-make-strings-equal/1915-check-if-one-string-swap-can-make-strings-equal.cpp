class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // if(s1 == s2)return true;
        // vector<char> s1_misplaced_char,s2_misplaced_char;
        // int cnt = 0;
        // for(int i=0; i<s1.size(); i++){
        //     if(s1[i] != s2[i]){
        //         if(cnt <= 1){
        //             s1_misplaced_char.push_back(s1[i]);
        //             s2_misplaced_char.push_back(s2[i]);
        //             cnt++;
        //         }else{
        //             return false;
        //         }
        //     }
        // }
        // if(cnt == 1)return false;
        // if(s1_misplaced_char[0] == s2_misplaced_char[1] && 
        //     s1_misplaced_char[1] == s2_misplaced_char[0]){
        //         return true;
        // }
        // return false;

        if(s1 == s2)
            return true;
        int left = 0, right = s1.size()-1;
        while(s1[left] == s2[left])
            left++;
        while(s1[right] == s2[right])
            right--;
        swap(s2[right], s2[left]);
        return s1==s2;
    }
};