//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int gcd(int a,int b){
	    if(b == 0)return a;
	    return gcd(b,a%b);
	}
	
	int pour(int fromJug,int toJug,int d){
	    int from = fromJug;
	    int to =0;
	    int step =1;
	    
	    
	    while(from != d&&  to != d){
	        int temp =min(from,toJug - to);
	        
	        to += temp;
	        from -= temp;
	        
	        step++;
	        
	        if(from == d || to == d){
	            break;
	        }
	        
	        if(from == 0){
	            from = fromJug;
	            step++;
	        }
	        if(to == toJug){
	            to=0;step++;
	        }
	    }
	    return step;
	}
	int minSteps(int m, int n, int d)
	{
	    // Code here
        // To make sure that m is smaller than n
        if (m > n)
            swap(m, n);
        
        // For d > n we cant measure the water
        // using the jugs
        if (d > n)
            return -1;
        
        // If gcd of n and m does not divide d
        // then solution is not possible
        if ((d % gcd(n,m)) != 0)
            return -1;
        
        // Return minimum two cases:
        // a) Water of n liter jug is poured into
        //    m liter jug
        // b) Vice versa of "a"
        return min(pour(n,m,d),   // n to m
                   pour(m,n,d));  // m to n
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends