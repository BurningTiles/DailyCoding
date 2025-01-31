# Solution - 09 Dec 2024

---
## [3152. Special Array II](https://leetcode.com/problems/special-array-ii)

### cpp
```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<bool> ans;

        for(int i=1; i<n; ++i)
            prefix[i] = prefix[i-1] + ((nums[i]&1) == (nums[i-1]&1));
        
        for(auto &q:queries) {
            int cnt = prefix[q[1]] - (q[0] > 0 ? prefix[q[0]] : 0);
            ans.push_back(cnt == 0);
        }

        return ans;
    }
};
```
