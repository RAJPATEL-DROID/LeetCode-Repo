//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
    //     sort(arr,arr+n);
    //     sort(dep,dep+n);
    //     int i=0, j=1;
    // 	int platform = 1;
    	
    // 	while(i<n && j<n){
    // 	    if( arr[j] > dep[i])
    // 	        i++;
    // 	    else
    // 	        platform++;
    	       
    // 	    j++;
    // 	}
    // 	return platform;
        vector<pair<int,int>> vp;
        for(int i=0;i < n;i++){
            vp.push_back({arr[i],dep[i]});
        }
        
        sort(vp.begin(),vp.end());
        
        priority_queue<int,vector<int> , greater<int> > pq;
        
        pq.push(vp[0].second);
        for(int i=1;i < n;i++){
            if(pq.top() < vp[i].first)pq.pop();
            pq.push(vp[i].second);
        }
        
        return pq.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends