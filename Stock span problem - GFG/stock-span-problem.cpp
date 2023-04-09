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
       vector<int> ans;
       
       stack<pair<int,int> >s;
       
       for(int i= 0 ;i < n;i++){
           if(s.empty()){
              ans.push_back(-1);
           }else if(!s.empty() && price[i] < s.top().first){
                  ans.push_back(s.top().second);
           }else if(!s.empty() && price[i] >= s.top().first){
                  while(!s.empty() && price[i] >= s.top().first){
                     s.pop();
                  }
                  if(!s.empty())ans.push_back(s.top().second);
                  else ans.push_back(-1);
            }
            s.push({price[i],i});
        }
        for(int i=0; i< n;i++){
            ans[i] = i - ans[i];
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