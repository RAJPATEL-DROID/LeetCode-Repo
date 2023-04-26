//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> ans;
        
        
        // First We insert 3 element in the queue and also keep max_ele;
        for(int i=0 ; i <k ; i++){
          while(!dq.empty() && dq.back() < a[i]){
              dq.pop_back();
          }
          
          dq.push_back(a[i]);
        }
        
        ans.push_back(dq.front());
        
        
        // Now traverse rest of the Array from k to n and push the ele in the back and take care of the max_ele
        for(int i= k ; i < n ;i++){
            if(dq.front() == a[i-k])dq.pop_front();
            
            while(!dq.empty() && dq.back() < a[i]){ dq.pop_back(); }
            
            dq.push_back(a[i]);
            ans.push_back(dq.front());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends