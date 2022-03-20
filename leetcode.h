#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <unordered_set> // http://www.cplusplus.com/reference/unordered_set/unordered_set/count/
#include <algorithm>
#include <math.h>
using namespace std;

// Print vector 
template <typename T>
void display(const vector<T>& vec)
{
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void display(const vector<vector<T>>& vec)
{
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        display(*it);
}
