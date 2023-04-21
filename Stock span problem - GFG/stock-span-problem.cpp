//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int> > s;
       vector<int> ans(n,1);
       for(int i=0; i< n; i++){
          if(s.empty()){
            ans[i] = -1;
          }else{
              while(!s.empty() && s.top().first <= price[i]){
                  s.pop();
              }
              if(!s.empty())ans[i]  = s.top().second;
              else ans[i] = -1;
          }
          s.push({price[i],i});
       }
       
       for(int i=0; i< n; i++){
           ans[i] = i- ans[i];
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends