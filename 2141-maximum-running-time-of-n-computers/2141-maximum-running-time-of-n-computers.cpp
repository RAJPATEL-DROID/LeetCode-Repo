class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // sort(A.begin(), A.end());
        // long long sum = accumulate(A.begin(), A.end(), 0L);
        // int k = 0, na = A.size();
        // while (A[na - 1 - k] > sum / (n - k))
        //     sum -= A[na - 1 - k++];
        // return sum / (n - k);
        
        long sumPower = 0;
        for (int power : batteries)
            sumPower += power;
        long left = 1, right = sumPower / n;
        
        while (left < right){
            long target = right - (right - left) / 2;
            long extra = 0;
            
            for (int power : batteries){
                if(power < target)extra += power;
                else extra += target;
            }
            

            if (extra >= (long)(n * target))
                left = target;
            else
                right = target - 1;
        }
        return left;
    }
};