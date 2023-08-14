//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;
        for(int i=0; i<nums.size(); i++)
            x=x^nums[i];
        
        int temp = 1;
        while((temp&x) == 0)temp *= 2;
        int g1,g2;
        g1=g2=0;
        
        for(int i=0;i < nums.size(); i++){
            if((temp & nums[i]) == 0){
                g1 = g1^nums[i];
            }else{
                g2 ^= nums[i];
            }
        }
        
        vector<int>v(2);
        if(g1<g2){
            v[0] = g1;
            v[1] = g2;
        }else{
            v[0] = g2;
            v[1] = g1;
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends