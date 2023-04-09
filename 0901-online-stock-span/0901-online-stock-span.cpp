class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int> > s;
    
    int next(int p) {
        int ans =1;
        while(!s.empty() && s.top().first <= p){
            ans += s.top().second;
            s.pop();
        }
        s.push({p,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */