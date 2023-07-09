//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        // BRUTE FORCE
        // if(n==1 && arr[0]>1)return 1;
        // else if(n==1 && arr[0] == 1)return arr[0]+1;
        
        // sort(arr,arr+n);
        // for(int i=0;i < n-1;i++){
        //     if(arr[i]>0){
        //         if(arr[i-1] <= 0 && arr[i] != 1)return 1;
        //         if(arr[i+1]-arr[i] > 1)return arr[i]+1;
        //         else continue;
        //     }else continue;
        // }
        
        // if(arr[n-1]<0)return 1;
        // if(arr[n-2]>=0 && arr[n-1]-arr[n-2] ==1)return arr[n-1]+1;
        // else return 1;
        
        /* Using Sorting 
        O(NLogN) => time
        O(N) => space
        int cnt = 1;
        
        sort(arr, arr+n);
        
        for(int i=0; i<n; i++)
        {
            if(cnt == arr[i] && arr[i] <= n+1) cnt++;
            
            if(cnt > arr[i]) {
                continue;
            }
            
            if(arr[i] > cnt){
                return cnt;
            }
        }
        
        return cnt;
        */
        
        // O(N)
        
        for(int i=0; i< n;i++){
            if(arr[i] > 0 && arr[i] < n+1){
                if(arr[arr[i]-1] != arr[i]){
                    swap(arr[i],arr[arr[i]-1]);
                    i--;
                }
            }
        }
        
        for(int i=0; i < n;i++){
            if(arr[i] != i+1)return i+1;
        }
        
        return n+1;
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends