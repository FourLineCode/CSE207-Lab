#include <bits/stdc++.h>
using namespace std;

/*
Input-

5 7 12 4 0 4 6 8 67 34 23 5 0 44 33 22 6 0

Output-

7 5 34 67 8 6 4 33 44
*/

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

        if (n != 0)
        {
            s.push(n);
        }
        else
        {
            int x = s.top();
            s.pop();
            x = s.top();
            s.pop();

            while (s.size())
            {
                x = s.top();
                s.pop();
                q.push(x);
            }
        }
    }

    while (q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}