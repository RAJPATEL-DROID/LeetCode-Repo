class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n),result;

        stack<int> s;

        for(int i =0 ; i< n;i++){
            indices[i] = i;
        }

        sort(indices.begin(),indices.end(),[&](int lhs,int rhs){return positions[lhs] < positions[rhs];});

        for(int currInd : indices){
            if(directions[currInd] == 'R'){
                s.push(currInd);
            }
            else{
                while(!s.empty() && healths[currInd] > 0){
                    int topInd = s.top();
                    s.pop();

                    if(healths[topInd] > healths[currInd]){
                        healths[topInd]--;
                        healths[currInd] = 0;
                        s.push(topInd);
                    }else if(healths[topInd] < healths[currInd]){
                        healths[topInd] = 0;
                        healths[currInd]--;
                    }else{
                        healths[topInd] = 0;
                        healths[currInd] = 0;
                    }
                }
            }
        }

        for(int i=0; i< n;i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }

        return result;
    
    }
};