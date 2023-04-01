class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // Brute Force/ Greedy Approach
//         int count = 0;
//         while(start > 0 && goal > 0){
//             if( (start&1) != (goal&1) )count++;
//             start >>= 1;
//             goal >>= 1;
//         }
        
//         while(start > 0){
//             if( start&1)count++;
//             start >>= 1;
//         }
//         while(goal > 0){
//             if( goal&1 )count++;
//             goal >>= 1;
//         }
//         return count;
        
        
        // When We take XOR of two numbers,all bits which are different will be set in the result
        // so a ^ b will have all the different bits set.
        
        int ans = start ^ goal;
        
        // now we will calculate the number of set bits using Brian Kernighan’s Algorithm
        // x-1 will flip all the bits from rightmost set bit and all bits on the right of it
        
        int count =0;
        
        while(ans>0){
            ans = ans & (ans-1);
            count++;
        }
        return count++;
    }
};