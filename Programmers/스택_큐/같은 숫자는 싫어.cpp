#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    return arr.erase(unique(arr.begin(), arr.end()), arr.end());
}