//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int minSum =0;
        int sum1=0,sum2=0,sum3=0;
        
        sum1 = accumulate(s1.begin(),s1.end(),0);
        sum2 = accumulate(s2.begin(),s2.end(),0);
        sum3 = accumulate(s3.begin(),s3.end(),0);
        
        int i_1=0,i_2=0,i_3=0;
        while(1<2){
            if(sum1 == sum2 && sum1 == sum3){
                return sum1;
            }else{
                minSum = min(sum1,min(sum2,sum3));
            }
            
            if(sum1 != minSum){
                sum1 -= s1[i_1++];
            }
            if(sum2 != minSum){
                sum2 -= s2[i_2++];
            }
            if(sum3 != minSum){
                sum3 -= s3[i_3++];
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends