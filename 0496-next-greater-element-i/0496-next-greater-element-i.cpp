class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        stack<int> s;
        unordered_map<int,int> m;
        for(int i =0;i < nums2.size(); i++){
            int n = nums2[i];
            while(!s.empty() && s.top() < n){
                m[s.top()]  = n;
                s.pop();
           }
            s.push(n);
        }
        for(int i =0 ; i < nums1.size(); i++){
            if(m.find(nums1[i]) != m.end()){
                ans[i] = m[nums1[i]];
            }
        }
        return ans;
    }
};