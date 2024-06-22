class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        int i =0, j =0;
        int cnt =0,ans =0;
        
        while( j < arr.size()){
            if(cnt < target){
                if(arr[j]%2 == 1){
                   cnt++; 
                }
                if(cnt == target)ans++;
                j++;
            }else{
                if(arr[j]%2 == 1){
                    while(arr[i]%2 == 0 && i < j){
                        i++;
                        ans++;
                    }
                    cnt--;i++;
                    cnt++;ans++;j++;
                }else{
                    int temp  =i;
                    while(arr[temp]%2 != 1){
                        temp++;ans++;
                    }
                    j++;
                    ans++;
                }
            }
        }
        
        while(i < j && arr[i]%2 != 1){
            if(cnt == target)ans++;
            i++;
        }
        return ans;
    }
};