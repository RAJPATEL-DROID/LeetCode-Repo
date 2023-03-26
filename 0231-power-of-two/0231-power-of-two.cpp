class Solution {
public:
    bool isPowerOfTwo(int n) {
        return  n > 0  && !( n & (n-1)) ;
        // int count =0;
        // if(n<=0)return false;
        // while(n){
        //     count += n&1;
        //     n >>=1;
        // }
        // if(count ==1 )return true;
        // return false;
    }
};