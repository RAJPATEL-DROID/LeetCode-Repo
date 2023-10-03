class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[101] ={0};

        for(auto i : nums){
            arr[i]++;
        }
        int cnt = 0;
        for(auto i : arr){
            if(i > 1){
               cnt += (i*(i-1))/2;     
            }
        }
        return cnt;
    }
};