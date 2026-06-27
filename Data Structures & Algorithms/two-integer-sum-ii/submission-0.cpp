class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<numbers.size();i++) {
            auto x = mp.find(numbers[i]);
            if(x != mp.end()) { 
                ans.emplace_back(x->second+1);
                ans.emplace_back(i+1);
                break;
            }
            mp[target - numbers[i]] = i;
        }

        return ans;
    }
};
