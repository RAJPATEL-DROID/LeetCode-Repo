class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int>ans;
        priority_queue<pair<int,int> >pq;
        
        for(int i=0;i<k;i++){
            pq.push({a[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k;i<a.size();i++){
            pq.push({a[i],i});
           
            while(i-pq.top().second>=k)pq.pop();
           
            ans.push_back(pq.top().first);
        }
        return ans;

    }
};