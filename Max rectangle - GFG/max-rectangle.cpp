//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int histogramMaxArea(int arr[],int m){
        stack<int> s;
        int temp,res=0,curr =0;
        
        for(int i=0; i < m; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                temp = s.top();
                s.pop();
                curr = arr[temp] * (s.empty() ? i : (i - s.top() - 1));
                res = max(res,curr);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            temp = s.top();
            s.pop();
            curr = arr[temp] * (s.empty() ? m : (m - s.top() - 1));
            res = max(res,curr);
        }
        return res;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = histogramMaxArea(M[0],m);
        for(int i= 1; i < n; i++){
            for(int j= 0; j < m; j++){
                if(M[i][j] == 1)M[i][j] += M[i-1][j];
            }
            res = max(res,histogramMaxArea(M[i],m));
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends