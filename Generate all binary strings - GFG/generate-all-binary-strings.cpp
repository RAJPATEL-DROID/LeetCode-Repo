//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // Recursive Way
    // void printF(string ans,int num){
    //     if(num == 0){
    //         cout<<ans<<" ";
    //         return;
    //     }
    //     printF(ans+'0',num-1);
    //     if(ans.size() == 0 || ans.back() != '1'){
    //         printF(ans + '1',num-1);
    //     }
    // };
    
    // void generateBinaryStrings(int& num){
    //     //Write your code
    //     string ans = "";
    //     printF(ans, num);
    //     return;
    // }
    
    // Iterative Method
     void generateBinaryStrings(int& num){
        //Write your code
        queue<string> q;
        q.push("0");
        q.push("1");
        while(!q.empty()){
            string s = q.front();
            if(s.length() ==num)cout<<s<<" ";
            else{
                q.push(s+'0');
                if(s[s.length()-1] != '1')q.push(s+'1');
            }
            q.pop();
        }
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