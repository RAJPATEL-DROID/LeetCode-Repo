class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0,curr=0;
        for(auto i: gain){
            curr += i;
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};