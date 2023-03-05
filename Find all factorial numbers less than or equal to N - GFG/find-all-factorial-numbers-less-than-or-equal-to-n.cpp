//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> ans;
    int fact =1;
    void factorial(long long sum,long long i,long long N){
        if(sum > N)return;
        ans.push_back(sum);
        sum = sum*(i+1);
        factorial(sum,i+1,N);
        return; 
    }
    vector<long long> factorialNumbers(long long N)
    {
        factorial(1,1,N);
        return ans;         
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends