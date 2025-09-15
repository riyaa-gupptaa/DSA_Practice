#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    static bool mycompare(string &s1, string &s2)
    {
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> numbers;
        for (int a : nums)
        {
            numbers.push_back(to_string(a));
        }
        sort(numbers.begin(), numbers.end(), mycompare);
        if (numbers[0] == "0")
        {
            return "0";
        }
        string res = "";
        for (string &num : numbers)
        {
            res.append(num);
        }
        return res;
    }
};