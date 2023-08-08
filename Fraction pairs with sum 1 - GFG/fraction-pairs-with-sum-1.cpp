//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[]){
        
        // Dealing with Float 
        // unordered_map<float,int> s;
        // int cnt=0;
        // for(int i=0;i< n;i++){
        //     double fraction = (double)numerator[i]/(1.0*denominator[i]);
        //     if(s.find(1-fraction) != s.end()){
        //         cnt += s[1-fraction];
        //     }
        //     s[fraction]++;
        // }
        // return cnt;
        
        
        // Dealing with float numbers is risky work
        // Instead use following method where we use GCD to divide the numer and denominator 
        // Simplify each fraction (numerator[i], denominator[i]) by dividing both the numerator and denominator by their greatest common divisor (GCD). This simplification doesn't change the ratio of the fraction but makes it easier to work with.
        // For each simplified fraction (x, y), the code calculates the "desired" fraction (want_x, want_y), 
        // want_x = y - x and want_y = y.
        // Do, ans += fractionCount[(want_x, want_y)], If the desired fraction is found in fractionCount, its count is added to the ans variable.
        // Increments the count of the current simplified fraction (x, y) in the fractionCount dictionary.
        // return the answer. Maths for wanting y - x  and y is in most voted answer.
        map<pair<int, int>, int> fractionCount;
        int ans = 0;
    
        for (int i = 0; i < n ; i++)
        {
            int x = numerator[i];
            int y = denominator[i];
            int gcd = __gcd(x, y);
            x /= gcd;
            y /= gcd;
            int want_x = y - x;
            int want_y = y;
    
            if (fractionCount.find({want_x, want_y}) != fractionCount.end())
                ans += fractionCount[{want_x, want_y}];
    
            fractionCount[{x, y}]++;
    
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends