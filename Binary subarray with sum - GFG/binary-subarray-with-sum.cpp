//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        int i =0, j =0;
        int sum =0,cnt =0;
        
        while( j < N){
            if(sum < target){
                sum += arr[j];
                if(sum == target)cnt++;
                j++;
            }else{
                if(arr[j] == 1){
                    while(arr[i] == 0 && i < j){
                        i++;
                        cnt++;
                    }
                    sum--;i++;
                    sum += arr[j];cnt++;j++;
                }else{
                    int temp  =i;
                    while(arr[temp] != 1){
                        temp++;cnt++;
                    }
                    j++;
                    cnt++;
                }
            }
        }
        
        while(i < j && arr[i] != 1){
            if(sum == target)cnt++;
            i++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends