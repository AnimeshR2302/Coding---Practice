class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++) {
            if(mp.find(nums[i])!=mp.end()) {
                ans.emplace_back(mp[nums[i]]);
                ans.emplace_back(i);
                break;
            }
            else mp[target - nums[i]] = i;
        }

        return ans;
    }
};
