//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string s){
      //code here
        long long x=0,y=0;
        stack<char> s1,s2;
        s1.push(s[0]);
        if(X>Y){
            for(int i=1;i<s.size();i++){
                if(!s1.empty() && (s1.top() == 'p' && s[i] == 'r')){
                    s1.pop();
                    x++;
                }else{
                  s1.push(s[i]);  
                } 
            }
            
            s2.push(s1.top());
            s1.pop();
            
            while(!s1.empty()){
                if(!s2.empty() && (s2.top() == 'p' && s1.top() == 'r')){
                    s1.pop();
                    y++;
                    s2.pop();
                }else{
                  s2.push(s1.top());  s1.pop();
                } 
            }
        }
        else{
             for(int i=1;i<s.size();i++){
                if(!s1.empty() && (s1.top() == 'r' && s[i] == 'p')){
                    s1.pop();
                    y++;
                }else s1.push(s[i]);
            }
            
            s2.push(s1.top());
            s1.pop();
            
            while(!s1.empty()){
                if(!s2.empty() && (s2.top() == 'r' && s1.top() == 'p')){
                    s1.pop();
                    x++;
                    s2.pop();
                }else{
                  s2.push(s1.top());  s1.pop();
                } 
            }
        }
        return x*X + y*Y;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends