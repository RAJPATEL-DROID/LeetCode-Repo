//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
        // if(s1 == "0" || s2 == "0")return "0";
        
        // bool flag = false;
        // if(s1[0] =='-'){
        //     flag = true;
        //     s1[0] = '0';
        // }   
        // if(s2[0] == '-'){
        //     if(flag)flag=false;
        //     else flag  = true;
        //     s2[0] = '0';
        // }
        // long long n1 = s1.size()-1;
        // long long n2 = s2.size() -1;
        // vector<int> ans (n1 + n2 + 2,0);
        
        // for(int i= n1;i>=0;i--){
        //     for(int j= n2; j>=0 ;j--){
        //         ans[i + j + 1] = (s1[i] - '0')*(s2[j] - '0');
        //         ans[i+j] += ans[i + j + 1]/10;
        //         ans[i + j + 1] %= 10;
        //     }
        // }
        
        // int i=0;
        // while(i < ans.size() && ans[i] == 0)i++;
        
        // string s = "";
        // if(flag)s.push_back('-');
        
        // while(i < ans.size()){
        //     s.push_back(ans[i] + '0');
        //     i++;
        // }
        // return s;
        if(s1 == "0" || s2 == "0")
           return "0";
       
       // To check the negative digits
       bool neg1 = false;
       bool neg2 = false;
       if(s1[0] == '-')
           {
               neg1 = true;
               s1[0] = '0';
           }
       if(s2[0] == '-')
           {
               neg2 = true;
               s2[0] = '0';
           }
       
       
       // Declaring an vector of size of total no of digits in (s1 + s2) and intitializing it with 0
       vector<int> ans_vector (s1.size() + s2.size(), 0);
       
       // build the ans by multiplying one digit at the time
       for(int i=s1.size()-1; i>=0; i--)
       {
           for(int j=s2.size()-1; j>=0; j--)
           {
               ans_vector[i+j+1] += (s1[i] - '0')*(s2[j] - '0');      // += to add the carry 
               ans_vector[i+j] += ans_vector[i+j+1]/10;         // Putting the carry at it's position, which will be added by above line in next iteration
               ans_vector[i+j+1] %= 10; 
           }
       }
       
       // There might be some leading 0's in vector, which are not needed
       int i=0;
       while(i < ans_vector.size() && ans_vector[i] == 0)
           i++;
       
       // Converting the vector to string
       string ans = "";
       if( (neg1 == true && neg2 == false) || (neg1 == false && neg2 == true) )  // If one is positive and one is negative
           ans.push_back('-');
       
       while(i < ans_vector.size())
       {
           ans.push_back(ans_vector[i] + '0');
           i++;
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends