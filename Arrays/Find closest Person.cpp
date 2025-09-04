#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1=abs(x-z);
        int diff2=abs(y-z);
        if(diff1<diff2)
        {
            return 1;
        }
        else if(diff2<diff1)
        {
            return 2;
        }
        return 0;
    }
};