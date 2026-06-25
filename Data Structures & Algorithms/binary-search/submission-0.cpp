class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;

        while(l<=h) {
            int midx =l + (h-l)/2; 
            if(nums[midx] == target) return midx;

            if(nums[midx]<target) {
                l = midx+1;
            } else {
                h=midx-1;
            }
        }

        return -1;
    }
};
