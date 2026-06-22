class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> map;
        int max_freq = 0, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            max_freq = max(max_freq, map[s[i]]);
            if ((i - start + 1) - max_freq > k)
            {
                map[s[start]]--;
                start++;
            }
        }
        return s.size() - start;
    }
};