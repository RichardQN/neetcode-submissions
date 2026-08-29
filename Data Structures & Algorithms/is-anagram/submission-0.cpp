class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        unordered_map<char, int> n;

        for (char c : s) { m[c]++;}
        for (char c : t) { n[c]++;}
        return m == n;

    }
};
