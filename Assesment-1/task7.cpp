#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;

    int size;
    cin >> size;

    while (size--)
    {
        int n;
        cin >> n;

        q.push(n);
    }

    int k;
    cin >> k;

    while (k--)
    {
        s.push(q.front());
        q.pop();
    }

    while (s.size())
    {
        q.push(s.top());
        s.pop();
    }

    while (q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}