class Solution {
public:
    int rob(vector<int>& arr) {
        int n= arr.size();
        int prev1 =arr[0];
        int prev2 =0;
        
        for(int i=1;i< n; i++){
            int left = arr[i];
            if(i>1){
                left += prev2;
            }
            int right = prev1;
            int curr = max(left,right);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};