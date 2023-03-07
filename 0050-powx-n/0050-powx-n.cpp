class Solution {
public:
    double myPow(double x, int n){
        // Recursive Way O(N) recursive stack space
        // if(n==0)return 1;   
        // if(n < 0){
        //     n = abs(n);
        //     x = 1/x;
        // }
        // if(n%2 ==0){
        //     return myPow(x*x,n/2);
        // }else{
        //     return x*myPow(x,n-1);
        // }
        
        // Iterative Way O(1) space
        double num = 1;
        long long nn = n;
        if(nn < 0) nn = -nn;
        while(nn>0){
            if(nn%2==1){
                num = num * x;
                nn--;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        if(n < 0){
            num = 1.0/num;
        }
        return num;
    }
};