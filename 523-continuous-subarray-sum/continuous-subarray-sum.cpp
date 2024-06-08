#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Hash map to store the first occurrence of each remainder
        unordered_map<int, int> remainderMap;
        // Initialize with remainder 0 at index -1 to handle the case of subarray starting at index 0
        remainderMap[0] = -1;
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            
            // Adjust remainder to be positive if it's negative (C++'s % can return negative)
            if (remainder < 0) {
                remainder += k;
            }
            
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // If the same remainder has been seen before, check the subarray length
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Store the index of the first occurrence of this remainder
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};