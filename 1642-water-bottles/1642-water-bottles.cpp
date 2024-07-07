class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange){
            cnt += emptyBottles/numExchange;
            emptyBottles = (emptyBottles%numExchange) + (emptyBottles/numExchange);
            
        }
        return cnt;
    }
};