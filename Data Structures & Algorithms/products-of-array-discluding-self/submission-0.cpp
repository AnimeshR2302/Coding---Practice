class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), f=1,r=1;
        vector<pair<int,int>> v(n,{1,1});
        vector<int> ans(n,1);

        for(int i=0;i<n;i++) {
            f*=nums[i];
            r*=nums[n-i-1];

            v[i].first *= f;
            v[n-i-1].second *= r;
        }

        for(int i=0;i<n;i++) {
            if(i-1>=0) ans[i] *= v[i-1].first;
            if(i+1 < n) ans[i] *= v[i+1].second;
        }

        return ans;
    }
};