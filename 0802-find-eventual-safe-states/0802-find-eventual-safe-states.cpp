// TOPOLOGICAL SORT
// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> indegree(n);
//         vector<vector<int>> adj(n);

//         for (int i = 0; i < n; i++) {
//             for (auto node : graph[i]) {
//                 adj[node].push_back(i);
//                 indegree[i]++;
//             }
//         }

//         queue<int> q;
//         // Push all the nodes with indegree zero in the queue.
//         for (int i = 0; i < n; i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         vector<bool> safe(n);
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             safe[node] = true;

//             for (auto& neighbor : adj[node]) {
//                 // Delete the edge "node -> neighbor".
//                 indegree[neighbor]--;
//                 if (indegree[neighbor] == 0) {
//                     q.push(neighbor);
//                 }
//             }
//         }

//         vector<int> safeNodes;
//         for(int i = 0; i < n; i++) {
//             if(safe[i]) {
//                 safeNodes.push_back(i);
//             }
//         }
//         return safeNodes;
//     }
// };

// DFS Solution
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& pathVisit) {
        // If the node is already in the stack, we have a cycle.
        if (pathVisit[node]) {
            return true;
        }
        if (visit[node]) {
            return false;
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        pathVisit[node] = true;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, pathVisit)) {
                return true;
            }
        }
        // Remove the node from the stack.
        pathVisit[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[i].push_back(node);
            }
        }

        vector<bool> visit(n), pathVisit(n);

        for (int i = 0; i < n; i++) {
            dfs(i, adj, visit, pathVisit);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!pathVisit[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};