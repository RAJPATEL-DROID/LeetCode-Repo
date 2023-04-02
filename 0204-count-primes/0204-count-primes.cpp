class Solution {
public:
    int countPrimes(int N) {
        vector<int> sieve(N+1,1);
        for(int i=2;i*i <=N;i++){
            if(sieve[i] == 1)
            { for(int j = i*i; j <= N; j+=i){
                    sieve[j] = 0;
                }
            }
        }
        int ans=0;
        for(int i=2;i<N;i++){
            // cout<< i << " " << sieve[i] <<"\n";
            if(sieve[i] == 1){
                ans++;
            }
        }
        return ans;
    }
};