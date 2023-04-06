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
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            case '%':
                return true;
            }
            return false;
    
};

    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> s;
        
        for(int i= pre_exp.size()-1; i >=0; i--){
            
            if( isOperator(pre_exp[i]) == true ){
                string op1 = s.top(); s.pop();
                string op2 = s.top(); s.pop();
                string temp  = '(' + op1 + pre_exp[i] + op2 + ')';    
                
                s.push(temp);
            }else{
                string tmp = "";
                tmp += pre_exp[i];
                s.push(tmp);
            }
        }
        
        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends