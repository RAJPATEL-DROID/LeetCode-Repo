class Solution {
public:
   
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> heap;
        // for(int num : nums){
        //     heap.push(-1*num);
        //     if(heap.size()> k){
        //         heap.pop();
        //     }
        // }
        // return -1* heap.top();
        
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        for(int num: nums){
            minVal = min(minVal,num);
            maxVal = max(maxVal,num);
        }
        
        vector<int> count(maxVal-minVal + 1);
        for(int num : nums){
            count[num-minVal]++;
        }
        
        int remain = k;
        for(int i= count.size()-1; i  >= 0; i--){
            remain -= count[i];
            if(remain <= 0){
                return minVal + i;
            }
        }
        return -1;
    }
};