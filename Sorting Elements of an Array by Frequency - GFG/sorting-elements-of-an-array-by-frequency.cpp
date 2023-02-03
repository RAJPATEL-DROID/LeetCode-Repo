#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin >> n;
    unordered_map<int,int> m;
    vector<int> v;
    priority_queue<pair<int,int> > maxheap;
    

    for(int i = 0; i < n; i++){
        int c; cin >> c;
        m[c]++;
    }
    
    for(auto it = m.begin(); it != m.end();it++){
        maxheap.push({it->second,-1*(it->first)});
    }
    
    while(!maxheap.empty()){
        int freq = maxheap.top().first;
        int ele  = maxheap.top().second;
        for(int i=1;i <=freq; i++){
            cout<< -1*ele<< " ";
        }
        maxheap.pop();
    }
    cout<<"\n";
}


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}