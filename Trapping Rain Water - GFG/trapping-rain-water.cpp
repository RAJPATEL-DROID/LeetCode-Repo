//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> gr(n,0);
        stack<int> s;  
        
        // Greater element in right
        for(int i=n-1;i >= 0; i--){
            if(!s.empty() && s.top() > arr[i]){
                if(i != n-1 && s.top() < gr[i+1]){
                    gr[i] = gr[i+1];
                }else{
                    gr[i] = s.top();
                }
            }else{
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    if(i != n-1 && s.top() < gr[i+1]){
                        gr[i] = gr[i+1];
                    }else{
                        gr[i] = s.top();
                    }
                }
            }
            s.push(arr[i]);
        }
       while(!s.empty()){
           s.pop();
       }
        // greater element in left
        vector<int> gl(n,0); 
        for(int i=0; i < n; i++){
            if(!s.empty() && s.top() > arr[i]){
                if(i != 0 && s.top() < gl[i-1]){
                    gl[i] = gl[i-1];
                }else{
                    gl[i] = s.top();
                }
            }else{
                while(!s.empty() && s.top() <= arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    if(i != 0 && s.top() < gl[i-1]){
                        gl[i] = gl[i-1];
                    }else{
                        gl[i] = s.top();
                    }
                }
            }
            s.push(arr[i]);
        }
        
        long long res =0;
        for(int i=0;i <n;i++){
            // cout<<i<<" "<<gr[i]<<" "<<gl[i]<<"\n";
            int qnt = min(gr[i],gl[i]);
            res += (qnt==0)?0:qnt - arr[i];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends