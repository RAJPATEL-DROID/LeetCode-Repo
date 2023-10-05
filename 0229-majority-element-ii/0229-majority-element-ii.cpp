class Solution {
public: 
    vector<int> majorityElement(vector<int>& a) {
        // int target = nums.size()/3;

        // unordered_map<int,int> mp;
        // for(auto i: nums){
        //     mp[i]++;
        // }
        // vector<int> ans;
        // for(auto it: mp){
        //     if(it.second > target)ans.push_back(it.first);
        // }
        // return ans;

    int y(-1), z(-1), cy(0), cz(0);
    
	  for (const auto & x: a) 
	  {
		  if (x == y) cy++;
		  else if (x == z) cz++;
		  else if (! cy) y = x, cy = 1;
		  else if (! cz) z = x, cz = 1;
		  else cy--, cz--;
     }
      
     cy = cz = 0;
     for (const auto & x: a)
		 if (x == y) cy++;
			 else if (x == z) cz++;
  
	  vector<int> r;
	  if (cy > size(a)/3) r.push_back(y);
	  if (cz > size(a)/3) r.push_back(z);
	  return r;

    }
};