//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    void merge(int low, int mid, int high, int arr[])
    {
        vector<int> temp;
        int right = mid+1;
        int left = low;
        while(left <= mid && right <= high)
        {
            if(arr[left] < 0)
            {
                temp.push_back(arr[left]);
                left++;
            }
            else if(arr[right] < 0)
            {
                temp.push_back(arr[right]);
                right++;
            }
            else
            {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i-low];
        }
    };
    void mergeSort(int low, int high, int arr[])
    {
        if(low >= high)
        {
            return;
        }
        int mid = low + (high-low)/2;
        mergeSort(low, mid, arr);
        mergeSort(mid+1, high, arr);
        merge(low, mid, high, arr);
    };
    public:
    void Rearrange(int arr[], int n)
    {
        mergeSort(0, n-1, arr);
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends