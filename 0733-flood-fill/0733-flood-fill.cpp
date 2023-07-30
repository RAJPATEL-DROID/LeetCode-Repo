class Solution {
public:
    // void func(int sr,int sc,vector<vector<int>>& image,int oldColor,int newColor,int i,int j){
    //     if(sr < 0 || sc <0 || sr == i || sr == j || image[sr][sc] != oldColor)return;
    //     image[sr][sc] = newColor;
    //     func(sr+1,sc,image,oldColor,newColor,i,j);
    //     func(sr,sc+1,image,oldColor,newColor,i,j);
    //     func(sr-1,sc,image,oldColor,newColor,i,j);
    //     func(sr,sc-1,image,oldColor,newColor,i,j);
    // }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // DFS  
        int oldColor = image[sr][sc];
        // if(oldColor == color)return image;
        // int x = image.size(),y = image[0].size();
        // func(sr,sc,image,oldColor,color,x,y);
        // return image;
        
        // BFS
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc] =1;
        image[sr][sc] = color;
        
        queue<pair<int,int> > q;
        q.push({sr,sc});
        
        vector<int> dir = {-1,0,1,0,-1};
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                pair<int,int> p  = q.front();
                q.pop();
                
                for(int i =0; i < 4; i++){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    
                    if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0 &&  image[r][c] == oldColor){
                        image[r][c] = color;
                        vis[r][c] = 1;
                        q.push({r,c});
                    } 
                }
            }
        }
        
        return image;
        
    }
};