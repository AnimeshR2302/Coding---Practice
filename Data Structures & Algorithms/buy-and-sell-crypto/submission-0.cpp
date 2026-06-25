class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int xmin=prices[0], xmax = -1;
        
        for(int& cur: prices) {
            xmax = max(cur-xmin,xmax);
            if(cur<xmin) xmin = cur;
        }

        return xmax;
    }
};