class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
//         sort(arr.begin(),arr.end());
//         int diff = arr[1] - arr[0];
        
//         for(int i=2;i < arr.size();i++){
//             if(arr[i] - arr[i-1] != diff)return false;
//         }
//         return true;
        
//     }
        int minValue = *std::min_element(arr.begin(), arr.end());
        int maxValue = *std::max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            // If arr[i] is at the correct index, move on.
            if (arr[i] == minValue + i * diff) {
                i += 1;
                
            // If arr[i] doesn't belong to this arithmetic sequence, return false.
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
                
            // Otherwise, find the index j to which arr[i] belongs, swap arr[j] with arr[i].
            } else {
                int j = (arr[i] - minValue) / diff;
                
                // If we find duplicated elements, return False.
                if (arr[i] == arr[j]) {
                    return false;
                }
                
                // Swap arr[i] with arr[j].
                swap(arr[i], arr[j]);
            }
        }
        
        return true;
    }
};