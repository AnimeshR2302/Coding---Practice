class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        set<pair<int,int>> s;
        int idx=0;

        while(idx < nums.size()) {
            auto mi = mp.find(nums[idx]);
            auto si = mi!=mp.end() ? s.find({mi->second, mi->first}) : s.end();
            auto cnt = mi!=mp.end() ? mi->second + 1 : 1;

            while(idx+1 <nums.size() && nums[idx] == nums[idx+1]) {
                cnt++;
                idx++;
            }

            mp[nums[idx]] = cnt;

            if(si!=s.end()) {
                s.erase(si);
                s.insert({cnt, nums[idx]});
            } else if(s.size() < k) {
                s.insert({cnt, nums[idx]});
            } else {
                if(s.begin()->first<cnt) {
                    s.erase(s.begin());
                    s.insert({cnt, nums[idx]});
                }
            }
            idx++;
        }

        vector<int> ans;
        ans.reserve(s.size());
        for(auto& p: s) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
};