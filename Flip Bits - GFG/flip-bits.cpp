//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int temp[n];
        int currSum = 0;
        int maxSum =0;
        int cnt = 0;
        for(int i=0; i< n; i++){
            if(a[i] == 0)temp[i] =1;
            else{
                temp[i] = -1;
                cnt++;
            }
            currSum += temp[i];
            if(currSum> maxSum)maxSum = currSum;
            if(currSum < 0)currSum =0;
        }
        return cnt + maxSum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends