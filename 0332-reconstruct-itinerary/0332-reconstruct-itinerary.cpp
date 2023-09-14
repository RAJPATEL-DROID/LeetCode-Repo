class Solution {
public:
    unordered_map<string,vector<string>> graph;
    vector<string> route;
    int numTickets =0;
    
    void dfs(string fromStation, vector<string>& temp){
       temp.push_back(fromStation);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return;
        }
        
        vector<string>& neighbors = graph[fromStation];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i =0; route.empty() &&i< neighbors.size(); i++) {
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            dfs(toAirport, temp);
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        // remove the current vertice
        temp.pop_back();
    }

    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        
        if(numTickets == 0)return route;
        for(auto& itr : tickets){
            graph[itr[0]].push_back(itr[1]);
        }
        
        for(auto& mp: graph){
            sort(mp.second.begin(), mp.second.end());
        }
        
        vector<string> temp;
        dfsRoute("JFK", temp);
        return route;
        
    }
    
  
    
    void dfsRoute(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return;
        }
        
        vector<string>& neighbors = graph[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i =0; route.empty() &&i< neighbors.size(); i++) {
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            dfsRoute(toAirport, temp);
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        // remove the current vertice
        temp.pop_back();
    }
};