class Solution {
public:
    unordered_map<string,vector<string>> graph;
    vector<string> route;
    int numTickets =0;
    
    void dfs(string fromStation, vector<string>& temp){
        temp.push_back(fromStation);
        
        if(temp.size() == numTickets + 1){
            route  = temp;
            return;
        }
        
        vector<string>& neighbours = graph[fromStation];
        
        for(int i=0; route.empty() && i < neighbours.size(); i++){
            string toAirport = neighbours[i];
            
            neighbours.erase(neighbours.begin() + i);
            
            dfs(toAirport,temp);
            
            neighbours.insert(neighbours.begin() + i, toAirport);
                        
        }
        
        temp.pop_back();
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        
        for(auto& itr : tickets){
            graph[itr[0]].push_back(itr[1]);
        }
        
        for(auto& mp: graph){
            sort(mp.second.begin(), mp.second.end());
        }
        
        vector<string> temp;
        dfs("JFK", temp);
        return route;
        
    }
};