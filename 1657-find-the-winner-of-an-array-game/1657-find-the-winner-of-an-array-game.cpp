class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // int winner =arr[0];
        // int cnt =0;
        // queue<int> q;
        // int n = arr.size();
        // int i=1;
        // while(i < n){
        //     if(arr[i] < winner){
        //         cnt++;
        //         if(cnt == k)return winner;
        //         q.push(arr[i]);
        //     }else{
        //         cnt =1;
        //         q.push(winner);
        //         winner = arr[i];
        //         if(cnt == k)return winner;
        //     }
        //     i++;
        // }

        // if(k > n)return winner;
        // while(!q.empty()){
        //     int temp = q.front();
        //     if(temp < winner){
        //         cnt++;
        //         if(cnt == k)return winner;
        //         q.push(temp);
        //     }else{
        //         cnt =1;
        //         q.push(winner);
        //         winner = temp;
        //     }
        //     q.pop();
        // }

        // int maxEle = arr[0];
        // for(int i=1; i< arr.size(); i++){
        //     maxEle = max(maxEle,arr[i]);
        // }

        int curr= arr[0];
        int cnt =0;

        for(int i=1; i< arr.size(); i++){
            int opponent = arr[i];
            if(curr > opponent){
                cnt++;
            }else{
                curr = opponent;
                cnt =1;
            }
            if(cnt == k ){
                return curr;
            }
        }
        return curr;
    }
};