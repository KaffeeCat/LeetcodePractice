#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
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
