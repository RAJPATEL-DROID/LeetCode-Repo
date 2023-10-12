/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();

        int l = 1;
        int r = len - 2;

        // Find Peak Index
        while(l != r){
            int testInd = (l + r) >> 1;
            if(mountainArr.get(testInd) < mountainArr.get(testInd + 1)){
                l = testInd + 1;
            }else{
                r = testInd;
            }
        }
        int peakInd = l;
        // Find Target in 0 to Peak Index
        l = 0;
        r = peakInd;
        while(l != r){
            int testInd = (l + r) >> 1;
            if(mountainArr.get(testInd) < target){
                l = testInd + 1;
            }else{
               r = testInd;
            }
        }
        if(mountainArr.get(l) == target){
            return l;
        }

        l = peakInd + 1;
        r = len -1;
        while(l != r){
            int testInd = (l + r) >> 1;
            if(mountainArr.get(testInd) > target){
                l = testInd + 1;
            }else{
                r  = testInd;
            }
        }

        if(mountainArr.get(l) == target){
            return l;
        }

        return -1;

    }
};