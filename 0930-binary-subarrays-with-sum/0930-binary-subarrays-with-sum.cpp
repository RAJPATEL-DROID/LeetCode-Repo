class Solution {
public:
    int atmost(vector<int>& A, int S){
        if (S < 0) return 0;
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            S -= A[j];
            while (S < 0)
                S += A[i++];
            res += j - i + 1;
        }
        return res;
    }; 
    
    int numSubarraysWithSum(vector<int>& A, int S) {
        // unordered_map<int, int> c({{0, 1}});
        // int psum = 0, res = 0;
        // for (int i : A) {
        //     psum += i;
        //     res += c[psum - S];
        //     c[psum]++;
        // }
        // return res;
        
        return atmost(A,S) - atmost(A,S-1);
    }
};