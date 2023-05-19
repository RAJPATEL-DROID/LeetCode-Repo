//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int i=0,j=0,k=0;
        int res=INT_MAX;
        string str;
        while(j<str1.length() && k<str2.length()){
            if(str1[j]==str2[k]){
                k++;
            }
            if(k==str2.length()){
                i=j;
                k=str2.length()-1;
                while(i>=0 && k>=0){
                    if(str1[i]==str2[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                if(res>j-i+1){
                    res=j-i+1;
                    str=str1.substr(i,j-i+1);
                }
                k=0;j=i+1;
            }
            j++;
        }
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends