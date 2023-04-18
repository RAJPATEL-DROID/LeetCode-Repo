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
                
                // Here we are finding the index of next smaller element and prev. smaller element 
                // at a same time
                
                // index of prev smaller element
                int leftBoundary = s.empty()?-1:s.top();
                
                // index of next smaller element
                int rightBoundary = i;
                
                // count of subarray where mid is the minimum element
                long count = (mid - leftBoundary)*(rightBoundary - mid) % mod;
                
                // add the total sum of all subarrays, min(b) where b was minimum element
                z += (count * arr[mid])%mod;
                z %= mod;
            }
            s.push(i);
            
        }
        
        return (int)z;}
};