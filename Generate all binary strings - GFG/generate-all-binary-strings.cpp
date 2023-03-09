//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void printF(string ans,int num){
        if(num == 0){
            cout<<ans<<" ";
            return;
        }
        printF(ans+'0',num-1);
        if(ans.size() == 0 || ans.back() != '1'){
            printF(ans + '1',num-1);
        }
    };
    
    void generateBinaryStrings(int& num){
        //Write your code
        string ans = "";
        printF(ans, num);
        return;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends