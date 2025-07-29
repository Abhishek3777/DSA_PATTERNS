#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i], parent);
}

void unionSet(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[y_parent] = x_parent;
        rank[x_parent]++;
    }
}

int main()
{

    int n = 7;
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    unionSet(1, 2, parent, rank);
    unionSet(2, 3, parent, rank);
    unionSet(4, 5, parent, rank);
    unionSet(6, 5, parent, rank);

    // Sample find
    cout << "Parent of 3: " << find(3, parent) << endl;
    cout << "Parent of 6: " << find(6, parent) << endl;

    if (find(3, parent) == find(1, parent))
    {
        cout << "3 and 1 are in the same set" << endl;
    }

    return 0;
}