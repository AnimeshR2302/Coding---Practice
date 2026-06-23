class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int bucketnum = 0;
        string temp; 
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        
        for(string s: strs) {
            temp = s;
            if(temp.length()>=2) sort(temp.begin(),temp.end());

            if(mp.find(temp) != mp.end()) ans[mp[temp]].emplace_back(s);
            else {
                mp[temp] = bucketnum;
                ans.emplace_back(vector<string>());
                ans[bucketnum++].emplace_back(s);
            }
        }

        return ans;
    }
};