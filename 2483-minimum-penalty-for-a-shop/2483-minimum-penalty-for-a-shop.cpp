class Solution {
public:
    int bestClosingTime(string cust) {
        int currPenalty = count(cust.begin(),cust.end(),'Y');
        int minPenalty = currPenalty;
        int earlyHour = 0;
        
        for(int i=0; i < cust.size(); i++){
            if(cust[i] == 'Y')currPenalty--;
            else currPenalty++;
            if(currPenalty < minPenalty){
                earlyHour =  i + 1;
                minPenalty = currPenalty;
            }
        }
        return earlyHour;   
    }
};