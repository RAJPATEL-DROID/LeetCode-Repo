//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//   bool isOperator(char c){
//             switch(c){
//                 case '+':
//                 case '/':
//                 case '*':
//                 case '-':
//                 case '^':
//                 case '%':
//                     return true;
//             }
//             return false;
//         }
//     string pretoIn(string s){
        
//         stack<string> st;
//         for(int i = s.size()-1; i >= 0;i--){
//             if(isOperator(s[i])){
//                 string s1 = st.top(); st.pop();
//                 string s2 = st.top(); st.pop();
                
//                 string temp = '(' + s1 + s[i] + s2 + ')';
//                 st.push(temp);
//             }else{
//                 string temp(1,s[i]);
//                 st.push(temp);
//             }
//         }
//         return st.top();
//     };
    
//     bool isChar(char c){
//         if(c != '+' && c != '-' && c != '*' && c!= '/' && c != '^' && c != '%' && c!= '(' && c != ')')return true;
//         return false;
//     }
    
//     int precedence(char c){
//         if(c == '^')return 3;
//         else if(c == '*' || c == '/')return 2;
//         else if(c == '+' || c == '-')return 1;
//         else return -1;
//     }
//     string inToPost(string s){
//         stack<char> st;
//         string ans = "";
//         for(int i=0;i < s.size(); i++ ){
//             if(isChar(s[i])){
//                 ans +=s[i]; 
//             }else if(s[i] == '('){
//                 st.push(s[i]);
//             }else if(s[i] == ')'){
//                 while( st.top() != '('){
//                     ans += st.top();
//                     st.pop();
//                 }
//                 st.pop();
//             }else{
//                 while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
//                     ans += st.top();
//                     st.pop();
//                 }
//                 st.push(s[i]);
//             }
//         }
        
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
//         }
//         return ans;
//     }
    
//     string preToPost(string pre_exp) {
        
//         string ans = pretoIn(pre_exp);
//         return inToPost(ans);
//     }

        // Direct Conversion
        bool isOperator(char c){
            switch(c){
                case '+':
                case '/':
                case '*':
                case '-':
                case '^':
                case '%':
                    return true;
            }
            return false;
        }
         string preToPost(string s) {
            stack<string> st;
            for(int i = s.size()-1; i >= 0;i--){
                if(isOperator(s[i])){
                    string s1 = st.top(); st.pop();
                    string s2 = st.top(); st.pop();
                    
                    string temp =  s1 + s2 + s[i];
                    st.push(temp);
                }else{
                    string temp(1,s[i]);
                    st.push(temp);
                }
            }
            return st.top();
             
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends