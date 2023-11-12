class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)return 0;

        unordered_map<int,vector<int>> adjList;

        for(int bus = 0; bus  < routes.size(); bus++){
            for(auto busStop : routes[bus]){\
                adjList[busStop].push_back(bus);
            }
        }

        queue<int> q;
        unordered_set<int> vis;

        for(auto bus : adjList[source]){
            q.push(bus);
            vis.insert(bus);
        }

        int busCount =1;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0; i< sz; i++){
                int bus = q.front();
                q.pop();

                for(auto stop : routes[bus]){
                    if(stop == target)return busCount;

                    for(auto nextBus : adjList[stop]){
                        if(!vis.count(nextBus)){
                            vis.insert(nextBus);
                            q.push(nextBus);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};