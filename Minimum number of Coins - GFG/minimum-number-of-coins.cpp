//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        // while(N>0){
        //     if(N/2000 != 0){
        //         ans.push_back(2000);
        //         N -= 2000;
        //     }else if(N/500 != 0){
        //         ans.push_back(500);
        //         N -= 500;
        //     }else if(N/200 != 0){
        //         ans.push_back(200);
        //         N -= 200;
        //     }else if(N/100 != 0){
        //         ans.push_back(100);
        //         N -= 100;
        //     }else if(N/50 != 0){
        //         ans.push_back(50);
        //         N -= 50;
        //     }else if(N/20 != 0){
        //         ans.push_back(20);
        //         N -= 20;
        //     }else if(N/10 != 0){
        //         ans.push_back(10);
        //         N -= 10;
        //     }else if(N/5 != 0){
        //         ans.push_back(5);
        //         N -= 5;
        //     }else if(N/2 != 0){
        //         ans.push_back(2);
        //         N -= 2;
        //     }else{
        //         ans.push_back(1);
        //         N -= 1;
        //     }
        // }
        // return ans;
        int coins[10]={1,2,5,10,20,50,100,200,500,2000};
        for(int i=9;i>=0;)
        {
            if(coins[i]<=N){
                N-=coins[i];
                ans.push_back(coins[i]);
            }else   i--; 
            
        }
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends