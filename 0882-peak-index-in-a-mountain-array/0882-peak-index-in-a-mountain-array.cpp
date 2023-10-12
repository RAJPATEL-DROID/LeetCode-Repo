class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int l =1; 
        // int h = arr.size()-3;
        
        // while(l <= h){
        //     int mid  = (l + h) >> 1;
        //     // cout<<mid<<"\n";
        //     if(arr[mid] < arr[mid+1]){
        //         l = mid+1;
        //     }else{
        //         h = mid-1;
        //         // cout<<h<<"\n";
        //     }
        // }
        // return l;
        
        int l=0;
        int h = arr.size()-1;
        while(l < h){
            int mid  = (l + h) >> 1;
            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }else{
                h = mid;
            }
        }
        return l;
    }
};