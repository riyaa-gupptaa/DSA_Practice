#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//Keep smaller digits at the start
//Get rid of the larger nums
string removeKdigits(string num, int k)
{
    string st; // use string as a stack

    for (char digit : num) {
        while (!st.empty() && k > 0 && st.back() > digit) {
            st.pop_back();
            k--;
        }
        st.push_back(digit);
    }

    // Remove any remaining digits from the end
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    // Remove leading zeros
    int start = 0;
    while (start < st.size() && st[start] == '0') {
        start++;
    }

    string result = st.substr(start);
    return result.empty() ? "0" : result;
}
//Time complexity is O(2N)+O(K)
//Space complexity is O(N)+O(N)