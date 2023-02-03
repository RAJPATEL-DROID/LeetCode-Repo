class Solution {
public:
    string frequencySort(string s) {
//         string ans = "";
//         unordered_map<char,int > m;
//         priority_queue<pair<int,char> > mheap;
        
//         for(int i=0;i< s.length(); i++){
//             m[s[i]]++;
//         }
        
//         for(auto it = m.begin(); it != m.end(); it++){
//             mheap.push({it->second, it-> first});
//         }
        
//         while(!mheap.empty()){
//             int freq = mheap.top().first;
//             int c = mheap.top().second;
//             for(int i= 1;i <= freq; i++){
//                 ans +=  c;
//             }
//             mheap.pop();
//         }
//         return ans;
        
        unordered_map<char, int> freqOfChar;
        for(char c : s) {
            freqOfChar[c] ++;
        }
        
        map<int,string> Str ;
        for(auto v: freqOfChar){
            int n = v.second;
            char c = v.first;
            Str[n] += string(n,c);
        }
        string res;
        for(auto rit = Str.rbegin(); rit != Str.rend(); ++rit) {
            res += rit->second;
        }
        return res;
    } 
};