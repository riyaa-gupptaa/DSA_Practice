#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool checkIfPangram(string sentence)
{
    vector<int> arr(26, 0);
    for (char &ch : sentence)
    {
        int index = ch - 'a';
        arr[index]++;
    }
    for (int &count : arr)
    {
        if (count == 0)
        {
            return false;
        }
    }
    return true;
}
// More optimal Solution
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> arr(26, 0);
        int count = 0;
        for (char &ch : sentence)
        {
            int index = ch - 'a';
            if (arr[index] == 0)
            {
                arr[index]++;
                count++;
            }
        }
        if (count != 26)
        {
            return false;
        }
        return true;
    }
};