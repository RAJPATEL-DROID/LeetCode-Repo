class Solution {
public:
     int f(string &str,int sign,int i,int result){
        if(i >= str.size() || str[i] < '0' || str[i] > '9'){
            return sign*result;
        }
        int temp =0;
        if(str[i] >= '0' or str[i] <= '9'){
            temp = str[i] - '0';
        } 
        if (result >  INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
        }
        return f(str,sign,i+1,result*10+temp);
     };

    int myAtoi(string str) {
           int sign = 1, base = 0, i = 0;
           while (str[i] == ' ') { i++; }   // skipping the whitespaces
           if (str[i] == '-' || str[i] == '+') {
               sign = 1 - 2 * (str[i++] == '-'); 
           }
           int ans = f(str,sign,i,0);
        return ans;
    }
};