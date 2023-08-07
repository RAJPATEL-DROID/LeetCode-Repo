class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        if(!a.size())return false;
        int low =0,high = (a.size()*a[0].size())-1;
        int m = a[0].size();
        int n = a.size();

        while(low<=high){
            int mid = low  + (high -low)/2;
            if(a[mid/m][mid%m]==target){
                return true;
            }else if(a[mid/m][mid%m] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    
    }
};