class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int cnt =0;
        unordered_map<int,int> m;
        int i=1;
        while(cnt != n){
            if(m.find(target-i) == m.end()){
                cnt++;
                m[i]++;                
            }
            i++;
        }
        long long sum=0;
        for(auto i : m){
            sum += i.first;
        }
        return sum;
    }
};