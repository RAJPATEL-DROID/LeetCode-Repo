//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void Generatepair(int ind,vector<int>& arr,int target,vector<vector<int> >& ans,vector<int>& temp){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            Generatepair(ind,arr,target-arr[ind],ans,temp);
            temp.pop_back();
        }
        
        Generatepair(ind+1,arr,target,ans,temp);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        // Your code here
        vector<vector<int> > ans;
        vector<int> temp;
        A.erase(unique(A.begin(),A.end()),A.end());
        Generatepair(0,A,B,ans,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends