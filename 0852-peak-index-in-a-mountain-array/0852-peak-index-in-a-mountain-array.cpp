class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l =0; 
        int h = arr.size()-1;
        
        while(l <= h){
            int mid  = (l + h) >> 1;
            // cout<<mid<<"\n";
            if(mid == 0 || mid == arr.size()-1){
                if(mid == 0 && arr[mid] > arr[mid+1]){
                     return mid;   
                }
                if(mid == arr.size()-1 && arr[mid] > arr[mid-1]){
                    return mid;
                }
                if(mid == 0){
                    l = mid+1;
                    continue;
                }else{
                    h = mid-1;
                    continue;
                }
            }
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                // cout<<arr[mid]<<"\n";
                return mid;
            }else if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }else{
                h = mid-1;
                cout<<h<<"\n";
            }
        }
        return 0;
    }
};