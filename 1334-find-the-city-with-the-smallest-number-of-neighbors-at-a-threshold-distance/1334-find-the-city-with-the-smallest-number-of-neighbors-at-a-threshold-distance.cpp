class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
	    
	    for(auto it : edges){
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
	    for(int i=0;i < n;i++)matrix[i][i] =0;
        
	    for(int k=0; k < n;k++){
	        for(int i=0;i < n;i++){
	            for(int j=0;j < n; j++){
	                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)continue;
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
        
        int cityCnt = n;
        int city = -1;
        for(int i=0;i <n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] <= distanceThreshold)cnt++;
            }
            
            if(cnt <= cityCnt){
                city = i;
                cityCnt = cnt;
            }
        }
        
        return city;
    }
};