class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        if (nums.empty()) return -1;
        int L = 0, R = nums.size() - 1, pivot;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        pivot = L;
        if (pivot && target >= nums[0] && target <= nums[pivot - 1]) L = 0, R = pivot - 1;
        else L = pivot, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[M] == target) return M;
            if (target > nums[M]) L = M + 1;
            else R = M - 1;
        }
        return -1;      
        
        
        
        // int start = 0;
//         int end = nums.size() - 1;
//         int mid;

//         while (start <= end) {
//             mid = start + (end - start) / 2;
//             cout << mid;

//             if (nums[mid] == target) {
//                 return mid;
                
//             } else if (nums[mid] >= nums[start]) {
//                 if (nums[start] <= target && target < nums[mid]) {
//                     end = mid - 1;
//                 } else {
//                     start = mid + 1;
//                 }

//             } else {
//                 if (nums[mid] < target && target <= nums[end]) {
//                     start = mid + 1;
//                 } else {
//                     end = mid - 1;
//                 }
//             } 

//         }


//         return -1;
    }
};