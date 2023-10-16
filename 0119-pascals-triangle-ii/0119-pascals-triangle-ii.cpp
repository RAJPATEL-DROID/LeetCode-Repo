class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansRow(rowIndex+1,0);
        ansRow[0] =1;

        for(int i=1;i<= rowIndex;i++){
            for(int j=i;j >=1; j--){
                ansRow[j] += ansRow[j-1];
            }
        }
        return ansRow;
    }
};