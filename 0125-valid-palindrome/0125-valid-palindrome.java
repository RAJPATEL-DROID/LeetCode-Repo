class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        String str ="";
        for(var i = 0; i < s.length(); i++){
            if( (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= '0' && s.charAt(i) <= '9') ){
                str += s.charAt(i);
            }
        }

        int i=0, j=str.length()-1;

        while(i < j)
        {
            if(str.charAt(i) == str.charAt(j)){
                i++;
                j--;
            }else
            {
                return false;
            }

        }
        return true;
    }
}