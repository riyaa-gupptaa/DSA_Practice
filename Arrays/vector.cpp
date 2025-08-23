//
//  vector.cpp
//  DSA_CLASS
//
//  Created by Riya Gupta on 24/10/24.
//
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

void explainVector() {
    vector<int> v; // Vector stores elements similarly to an array
    v.push_back(1);
    v.emplace_back(2); // Dynamically increases size and pushes 2 at the back

    // Vector of a pair datatype
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    v.emplace_back(3); // Different syntax than push_back

    vector<int> v1(5, 100); // {100,100,100,100,100}
    vector<int> v2(5);      // {0,0,0,0,0}
    vector<int> v3(5, 20);  // {20,20,20,20,20}
    vector<int> v4(v3);     // Copy of v3

    // Access elements in a vector
    vector<int> w = {20, 30, 40, 50, 60};
    vector<int>::iterator it = w.begin();
    it++;
    cout << *(it) << " " << endl; // Output: 30

    it += 2; // Move iterator two steps forward
    cout << *(it) << " " << endl; // Output: 50
    cout << *(w.begin()) << endl; // Output: 20
}

int main() {
    explainVector();
    return 0;
}
