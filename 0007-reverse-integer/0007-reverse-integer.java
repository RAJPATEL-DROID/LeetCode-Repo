class Solution {
    public int reverse(int x) {
        int ans =0;
        while(x != 0){
        
            int lastPositionNumber = x%10;
            if(ans > Integer.MAX_VALUE/10 || ans < Integer.MIN_VALUE/10){
                return 0;
            }else
            {
                ans = ans*10 + lastPositionNumber;
                x = x/10;
            }
            
        }
        return ans;
    }
}