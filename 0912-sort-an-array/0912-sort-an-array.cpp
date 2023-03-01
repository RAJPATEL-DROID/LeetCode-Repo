class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int high,vector<int>& tempArr){
        for(int i=left;i<mid+1;i++){
            tempArr[i] = nums[i];
        }
        
        for(int i =mid+1;i <= high;i++){
            tempArr[i] = nums[i];
        }
        
        int i=left,j = mid+1;
        while(i <= mid && j <= high){
            if(tempArr[i] < tempArr[j]){
                nums[left++] = tempArr[i++];
            }else{
                nums[left++] = tempArr[j++];
            }
        }
        
        while(i <= mid){
            nums[left++]  = tempArr[i++];
        }
        
        while(j  <= high){
            nums[left++] = tempArr[j++];
        }
    }
    void mergeSort(vector<int>& nums,int left,int right,vector<int>& tempArr){
        if(left >= right)
        {
            return;
        }
        int mid = (left + right) >> 1;
        mergeSort(nums,left,mid,tempArr);
        mergeSort(nums,mid+1,right,tempArr);
        
        merge(nums,left,mid,right,tempArr);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tempArray(nums.size());
        mergeSort(nums,0,nums.size()-1,tempArray);
        return nums;
    }
};