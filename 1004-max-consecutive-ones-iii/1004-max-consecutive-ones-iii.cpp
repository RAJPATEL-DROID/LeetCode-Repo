class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        int i =0, j =0,currZeroes =0;
        while( j < n ){
            if(nums[j] != 0){
                // cout<<"end"<<j <<"start" <<i<<"\n";
                len = max(len,j-i+1);
            }else{
                if(currZeroes < k){
                    currZeroes++;
                }else if(currZeroes == k){
                    while(nums[i] != 0){
                        i++;
                    }
                    i++;
                }
                // cout<<"end"<<j <<"start" <<i<<"\n";
                len = max(len,j-i+1);
            }
            j++;
        }
        // cout<<currZeroes<<"\n";
        // cout<<"end"<<j <<"start" <<i<<"\n";
        len = max(len,j-i);
        return len;
    }
};