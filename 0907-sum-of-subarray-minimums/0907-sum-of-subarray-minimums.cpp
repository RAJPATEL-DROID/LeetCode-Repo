class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1000000007;
        
        stack<int> s;
        long long z=0;
        
        for(int i=0;i <= arr.size();i++){
            while(!s.empty() && (i == arr.size() || arr[s.top()] >= arr[i])){
                int mid = s.top();
                s.pop();
                int leftBoundary = s.empty()?-1:s.top();
                int rightBoundary = i;
                
                // count of subarray where mid is the minimum element
                long count = (mid - leftBoundary)*(rightBoundary - mid) % mod;
                z += (count * arr[mid])%mod;
                z %= mod;
            }
            s.push(i);
            
        }
        
        return (int)z;}
};