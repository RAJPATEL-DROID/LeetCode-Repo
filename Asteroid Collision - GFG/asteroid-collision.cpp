//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &ast) {
        // code here
        vector<int> ans;
        stack<int> s;
        
        for(int i=0; i< n; i++){
            if(ast[i] < 0){
                
                int flag =1;
                while(!s.empty() && (abs(ast[i]) - s.top()) >= 0 ){
                    if(s.top() == abs(ast[i])){
                        flag =0;
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                if(s.empty() && flag){
                    ans.push_back(ast[i]);
                    
                }
            }else{
                s.push(ast[i]);
            }
        }
        
        vector<int> temp;
        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }
        for(int i=temp.size()-1; i >= 0; i--){
            if(temp[i] != 0)ans.push_back(temp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends