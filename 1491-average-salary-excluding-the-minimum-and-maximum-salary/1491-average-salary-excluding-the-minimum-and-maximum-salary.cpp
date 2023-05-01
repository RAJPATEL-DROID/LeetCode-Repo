class Solution {
public:
    double average(vector<int>& s) {
        int minS,maxS;
        minS = *min_element(s.begin(),s.end());
        maxS = *max_element(s.begin(),s.end());
        
        double sum = 0.0;
        for(int i=0 ; i < s.size(); i++){
            if( s[i] == minS || s[i] == maxS  )continue;
            else{
                sum += (double)s[i];
            }
        }
        sum = sum/(double)(s.size()-2);
        
        return sum; 
    }
};