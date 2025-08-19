#include<iostream>
#include<string>
using namespace std;

void printSubsequences(string str, string output, int index) {
    // Base Case
    if (index == str.length()) {
        cout << (output.empty() ? "\"\"" : output) << endl; // print "" for empty subsequence
        return;
    }

    // Choice 1: Exclude current character
    printSubsequences(str, output, index + 1);

    // Choice 2: Include current character
    printSubsequences(str, output + str[index], index + 1);
}

int main() {
    string str = "abc";
    cout << "Subsequences of " << str << " are:\n";
    printSubsequences(str, "", 0);
    return 0;
}
