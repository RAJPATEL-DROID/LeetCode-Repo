class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
//         
        int i=0,j=a[0].size()-1;
        int n=a.size();
        while(i<n && j>=0){
            if(a[i][j]==target){
                return true;
            }else if(a[i][j]>target){
                j--;            
            }else{
                 i++; 
            }
        }
        return false;
        // if(!a.size())return false;
        
//         int low =0;
//         int high = (a.size()*a[0].size())-1;
        
        
//         int m = a[0].size();

//         while(low<=high){
//             int mid = low  + (high -low)/2;
//             if(a[mid/m][mid%m]==target){
//                 return true;
//             }else if(a[mid/m][mid%m] < target){
//                 low = mid+1;
//             }else{
//                 high = mid-1;
//             }
//         }
//         return false;
    
    }
};