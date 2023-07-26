class Solution {
public:
    bool isValid(vector<int>& dist,int mid,double hour){
        
        double time=0.0;
        
        for(int i=0; i< dist.size(); i++){
            double t = (double)dist[i]/(double)mid;
            if(i == dist.size()-1)
                time += t;
            else
                time += ceil(t);
        }
        return time <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int h = 1e7;
        int minSpeed =-1;
        while(l <= h){
            int mid = (l+h) >> 1;
            
            if(isValid(dist,mid,hour)){
                minSpeed = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return minSpeed;
    }
};