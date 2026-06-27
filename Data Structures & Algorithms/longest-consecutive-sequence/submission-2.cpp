class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i: nums) pq.push(i);
        
        int prev = pq.top(); pq.pop();
        int ans = 1, xmax = 1;
        while(!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            
            if(cur == prev + 1) {
                ans++;
                prev = cur;
            } else if(prev == cur) {
                continue;
            } else { 
                xmax = max(xmax, ans);
                ans = 1;
                prev = cur;
            }
        } 
        xmax = max(xmax, ans);
        return xmax;
    }
};