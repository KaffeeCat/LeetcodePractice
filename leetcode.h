#include <iostream>
#include <vector>
#include <algorithm>
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
