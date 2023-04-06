//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isOperator(char c){
      switch(c){
          case '^':
          case '*':
          case '/':
          case '+':
          case '-':
          case '%':
            return true;
      }
      return false;
  }
    string postToInfix(string exp) {
        // Write your code here
        stack<string> s;
        for(int i= 0; i < exp.size(); i++){
            if(isOperator(exp[i])){
                string temp ="";
                string s1 = s.top();s.pop();
                string s2 = s.top();s.pop();
                temp += ')' + s1 + exp[i] + s2 + '(';
                s.push(temp);
            }else{
                string temp(1,exp[i]);
                s.push(temp);
            }
        }
        string st = s.top();
        reverse(st.begin(),st.end());
        return st;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends