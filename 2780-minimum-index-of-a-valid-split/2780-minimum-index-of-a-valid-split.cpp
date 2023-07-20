class Solution {
public:
    
    // Contest Solution
    
//     pair<int,int> findMostOccuring(vector<int>& nums){
//         unordered_map<int,int> m;
        
//         for(auto i: nums){
//             m[i]++;
//         }
//         int maxi =INT_MIN,max_ele =0;
//         for(auto it : m){
//             if(it.second > maxi){
//                 max_ele = it.first;
//                 maxi = it.second;
//             }
//         }
        
//         return make_pair(max_ele,maxi);
        
//     }
    
//     bool isValid(int curr_freq,int freq,int ind,int n){

    
//         if( (curr_freq * 2 > (ind+1)) &&  (((freq-curr_freq)*2) > (n-ind))  ){
            
//             // cout<<curr_freq*2<<" "<<ind+1<<" "<<freq*2<<" "<<n-ind<<"\n";
//             return true;
//         }
//         return false;
    
//     }
//     int minimumIndex(vector<int>& nums) {
        
//         // step 1. Find most Occuring element.
//         pair<int,int> tmp = findMostOccuring(nums);
//         int dom = tmp.first;
//         int freq = tmp.second;
//         // cout<<dom<<" "<<freq<< "\n";
        
//         // Step 2. Traverse from i = o to n and for each index check if 
//         // that index contains our dom, if dom is there, add in curr_freq and check 
//         // freq(curr_freq)* 2 > (i+1) && freq(freq-curr_freq)* 2> (n-i) => if true return i;
//         // else move forward
//         int i=0,curr_freq=0;
//         while(i < nums.size()){
//             if(nums[i] == dom){
//                 curr_freq++;
//                 if(isValid(curr_freq,freq,i,nums.size()-1))return i;
//             }
//             i++;
//         }
        
//         return -1;
//         // return 0;
        
//     }
    int minimumIndex(vector<int>& nums) {
        //find the majority element 
        int majority = nums[0], count = 0;
        for(auto n: nums){
            if(n == majority) count++;
            else count--;
            if(count == 0) { majority = n; count = 1; }
        }

        //count majority elements occurance
        int majCout = 0;
        for(auto n: nums) if(n == majority)  majCout++;

        //check if split is possible or not
        count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == majority) count++;
            if(count*2 > (i+1)  && (majCout - count)*2 > (nums.size() - i - 1)) return i;
        }
        return -1;
    }
};