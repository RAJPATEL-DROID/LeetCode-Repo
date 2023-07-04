class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        int x, sum;
        int n = nums.size();
        // Iterate through every bit
        for (int i = 0; i < 32; i++)
        {
          // Find sum of set bits at ith position in all
          // array elements
          sum = 0;
          x = (1 << i);
          for (int j=0; j< n; j++ )
          {
              if (nums[j] & x)
                sum++;
          }

          // The bits with sum not multiple of 3, are the
          // bits of element with single occurrence.
          if (sum % 3)
            result |= x;
        }

        return result;
    }
};