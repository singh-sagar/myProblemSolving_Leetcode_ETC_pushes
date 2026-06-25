class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int curr = 1, ans = 0, start = 0;
        if (k <= 1)
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr = curr * nums[i];
            while (curr >= k)
            {
                curr = curr / nums[start];
                start++;
            }
            ans = ans + (i - start + 1);
        }
        return ans;
    }
};