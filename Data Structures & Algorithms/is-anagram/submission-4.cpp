class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length(), ars[26] = {0}, art[26] = {0};

        for(int i=0;i<n;i++) {
            ars[s[i] - 'a']++;
            art[t[i] - 'a']++;
        }

        for(int i=0;i<26;i++) {
            if(ars[i] != art[i]) return false;
        }

        return true;
    }
};
