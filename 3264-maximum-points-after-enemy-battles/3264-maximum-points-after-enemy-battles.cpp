class Solution {
public:
    long long maximumPoints(vector<int>& e, int ce) {
        // TLE
        // sort(e.begin(),e.end());
        
        // if(e[0] > ce)return 0;
        //    if(e.size() == 1)
        //     {
        //         return ce/e[0];
        //     }
        //     long long point=1;
        //     ce =ce - e[0];
        //     int i=0,j=e.size()-1;

        //     while(i <= j){
        //         if(e[i] <= ce){
        //             ce = ce - e[i];
        //             point++;
        //         }else{
        //             ce = ce + e[j];
        //             j--;
        //         }
        //     }
        //     return point;

        // TLE
        // priority_queue<int> max_heap;
        // priority_queue<int,vector<int>,greater<int>> min_heap;

        // for(int i: e){
        //     min_heap.push(i);
        //     max_heap.push(i);
        // }

        // if(min_heap.top() > ce)return 0;

        // if(e.size() == 1){
        //     return ce/min_heap.top();
        // }

        // long long points=1;
        // ce = ce - min_heap.top();
        // while(!max_heap.empty()){
        //     if(min_heap.top() <= ce){
        //         ce = ce - min_heap.top();
        //         points++;
        //         // cout<<points<<" "<<min_heap.top()<<" "<<max_heap.top()<<"\n";
        //     }else{
        //         ce = ce + max_heap.top();
        //         max_heap.pop();
        //     }
        // }

        // return points++;

        // TC : O(N)
        // long sum=0;
        // int mini=INT_MAX;
        // for(int i=0;i<e.size();i++){
        //     mini=min(mini,e[i]);
        //     sum+=e[i];
        // }
        // sum-=mini;
        // if(mini> ce){
        //     return 0;
        // }
        // return (long)(sum+ce)/mini;


        // TC : O(nlogn)
        sort(e.begin(),e.end());
        
        if(e[0] > ce)return 0;
        if(e.size() == 1)
        {
            return ce/e[0];
        }
        long long point=0;
        int j=e.size()-1;

        while(j >= 0){
            if(e[0] <= ce){
                point += (ce)/e[0];
                ce %= e[0];
            }else{
                ce = ce + e[j];
                j--;
            }
        }
        return point;
    }
};