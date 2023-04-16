//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        long long sum1=0,sum2=0;
        vector<int> AevenOdd[2],BEvenOdd[2];
        for(int i =0; i<N;i++){
            sum1 += A[i];
            sum2 += B[i];
            
            if(abs(A[i])%2 ==0){
                AevenOdd[0].push_back(A[i]);
            }else{
                AevenOdd[1].push_back(A[i]);
            }
            
            if(abs(B[i])%2 ==0){
                BEvenOdd[0].push_back(B[i]);
            }else{
                BEvenOdd[1].push_back(B[i]);
            }
            
        }
        
        // If both array don't have same size then it's not possible to 
        // make A same like B as our operation only shift the values from one to other elements
        // Also if no of Odd/Even element in each array are not same then also 
        // We can't do the asked. As we can add/subtract 2 from even and it result into even
        // and similarly for odd. 
        if(sum1 != sum2 || (AevenOdd[0].size() != BEvenOdd[0].size())){
            return -1;
        }
        
        long long ans=0;
        
        for(int i=0;i <2;i++){
            
            // Sorting is necessary so we get minimum number of operations
            sort(AevenOdd[i].begin(),AevenOdd[i].end());
            sort(BEvenOdd[i].begin(),BEvenOdd[i].end());
            
            
            for(int j= 0; j < AevenOdd[i].size(); j++){
                // To make two elements equal we need to cover up the difference between two,
                //as we will add/subtract 2 from difference,so operations required to 
                // coverup the difference will be difference/2
                ans += abs(AevenOdd[i][j] - BEvenOdd[i][j])/2;
            }
        }
        // As we will be performing the Addition in one Element and Subtraction in Other Element,
        // We will totally perform the half of the operations only.
        return ans/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends