class Solution {
public:
   
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(int num : nums){
            heap.push(-1*num);
            if(heap.size()> k){
                heap.pop();
            }
        }
        return -1* heap.top();
    }
};