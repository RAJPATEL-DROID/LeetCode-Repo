class Solution {
public:
//     int generateString(string s,int n,int k){
//         if(n == 0){
//             return s[k-1]=='0':0?1;
//         }
//         string ans="";
//         for(int i=0;i<s.size();i++){
//             if(s[i] == '0'){
//                 ans += "01";
//             }else{
//                 ans += "10";
//             }
//         } 
//         return generateString(ans,n-1,k)
        
//     }
    int solve(int n,int k){
        if(n == 1 && k == 1){
            return 0;
        }
        int mid = (pow(2,n-1)) / 2;
        
        if(k <= mid){
            return solve(n-1,k);
        }else{
            return !solve(n-1,k -mid);
        }
    }
    int kthGrammar(int n, int k) {
        // string s ="0"; 
        // return (int)generateString(s,n-1,k)
        return solve(n,k);
        
    }
};