class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int h = letters.size()-1;
        char c=letters[0];
        while(l<=h){
            int mid = l+(h-l)/2;
            if(letters[mid]>target){
                c = letters[mid];
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return c;
    }
};