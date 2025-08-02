#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size();
    int five = 0, ten = 0;

    for (int bill : bills)
    {
        if (bill == 5)
        {
            five++;
        }
        else if (bill == 10)
        {
            if (five > 0)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else
        { // bill == 20
            if (ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}
// Time complexity is O(N)
// Space complexity is O(1)