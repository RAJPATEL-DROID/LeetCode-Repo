class Solution {
public:
    int check_maxSumOfLengthK(vector<int>a,int target,int k){
        int sum=0;
        for(int i=0;i<k;i++){sum +=a[i];}        
        if(sum>=target)return true;
        int l=0;
        int r=k;
        while(r  < a.size()){
            sum -=a[l++];
            sum += a[r++];
            if(sum>=target)return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low =1,high = nums.size()+1;
        bool ansPossible=false;
        while(low<high){
            int mid = low + (high -low)/2;
            if(check_maxSumOfLengthK(nums,target,mid)==true){
                ansPossible = true;
                high =mid;
            }else{
                low = mid+1;
            }
        }
        if(ansPossible)return low;
        return 0;
    }
}; 