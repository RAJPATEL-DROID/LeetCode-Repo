//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++



// You just explore the array one element by 1

// for each number there are 3 possible alphabet
// so you will have choice of choosing the 1 char out of 3 
                                                           
// we need method to store related char to respective no.
// 

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void GenerateString(int a[],int n,string s,unordered_map<int,char> m,int i,vector<string>& ans){
            if(s.size() == n){
                ans.push_back(s);
                return;
            }
            
            s.push_back(m[a[i]]);
            GenerateString(a,n,s,m,i+1,ans);
            s.pop_back();
            s.push_back(m[a[i]] + 1);
            GenerateString(a,n,s,m,i+1,ans);
            s.pop_back();
            s.push_back(m[a[i]] + 2);
            GenerateString(a,n,s,m,i+1,ans);
            s.pop_back();
            if( a[i] == 7 || a[i] == 9){
                s.push_back(m[a[i]] + 3);
                GenerateString(a,n,s,m,i+1,ans);
                s.pop_back();
            }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int,char> m;
        m[2] = 'a';
        m[3] = 'd';
        m[4] = 'g';
        m[5] = 'j';
        m[6] = 'm';
        m[7] = 'p';
        m[8] = 't';
        m[9] = 'w';
        vector<string> ans;
        GenerateString(a,N,"",m, 0,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends