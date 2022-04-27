class Solution {
public:
    char findTheDifference(string s, string t) {
        long long sumS = 0, sumT = 0;
        for(int i = 0; i < s.length(); i++)
            sumS += (int) s[i];
        for(int i = 0; i < t.length(); i++)
            sumT += (int) t[i];
        return (char)sumT-sumS;
    }
};