class Solution {
public:
    string reverseWords(string s) {
      // if string is immutable use additional space
//         vector<string> words;
//         stringstream ss(s);
//         string tmp;
//         while (ss >> tmp)
//             words.push_back(tmp);

//         string ans;
//         for (int i = words.size() - 1; i >= 0; --i) {
//             if (i != words.size() - 1) ans += " ";
//             ans += words[i];
//         }
//         return ans;
   
        // if string is mutable then  in-place solution
       reverse(s.begin(), s.end());
       int l = 0, r = 0, i = 0, n = s.size();
       while (i < n) {
           while (i < n && s[i] != ' ')
               s[r++] = s[i++];

           if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
        
    }
};