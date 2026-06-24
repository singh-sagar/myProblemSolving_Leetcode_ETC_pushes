class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        unordered_map<char, int> map;
        unordered_map<char, int> map1;
        int needed = 0;
        int matched = 0;
        int start = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (map1.count(s1[i]) == 0)
                needed++;
            map1[s1[i]]++;
            map[s2[i]]++;
        }

        for (auto const &pair : map1)
        {
            if (map[pair.first] == pair.second)
                matched++;
        }

        for (int i = s1.size(); i < s2.size(); i++)
        {
            if (matched == needed)
                return 1;
            int a = ++map[s2[i]];
            int b = --map[s2[start]];
            if (map1.count(s2[i]) && a == map1[s2[i]])
                matched++;
            if (map1.count(s2[start]) && b == map1[s2[start]])
                matched++;

            if (map1.count(s2[i]) && a - 1 == map1[s2[i]])
                matched--;
            if (map1.count(s2[start]) && b + 1 == map1[s2[start]])
                matched--;

            start++;
        }

        return matched == needed;
    }
};