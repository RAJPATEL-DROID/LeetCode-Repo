//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int temp =0;
        
        for(long long int i = 0; i< N;i++){
            temp ^= Arr[i];
        }
        long long int rightmost_setbit = temp & ~(temp-1);
        long long int set1=0,set2=0;
        for(int i =0; i < N; i++){
            if(rightmost_setbit & Arr[i]){
                set1 ^= Arr[i];
            }else{
                set2 ^= Arr[i];
            }
        }
        if(set1>=set2)return {set1,set2};
        return {set2,set1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends