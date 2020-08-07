/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> output;
        if (nums.size() < 2)
            return output;

        int tmp;
        int startInd = 0;
        int currInd = nums[startInd] - 1;

        startInd++;
        while (true)
        {
            while (nums[currInd] != -1 && currInd >= startInd)
            {
                tmp = nums[currInd] - 1;
                nums[currInd] = -1;
                currInd = tmp;
            }

            if (nums[currInd] == -1)
                output.push_back(currInd + 1);
            else if (currInd < startInd)
                nums[currInd] = -1;

            if (startInd < nums.size())
            {
                while (nums[startInd] == -1 && startInd < nums.size())
                {
                    startInd++;
                    if (startInd >= nums.size())
                        return output;
                }
            }
            else
                return output;

            currInd = nums[startInd] - 1;
            startInd++;
        }
    }
};