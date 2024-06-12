class Solution {
    public int fib(int n) {
            // if(n == 0)
            // {
            //     return 0;
            // }
            // if(n == 1 || n == 2){
            //     return 1;
            // }

            // return fib(n-1) + fib(n-2);

        // Iterative Solution
         int low = 0;
        int high = 1;
        switch (n) {
            case 0:
                return low;
            case 1:
                return high;
            default:
                while (n > 0) {
                    int temp = high;
                    high = high + low;
                    low = temp;
                    n--;
                }
        }
        return low;
    }
}