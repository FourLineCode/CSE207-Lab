#include <bits/stdc++.h>
using namespace std;

/*
Input - 

1 2 3 4 5 -1 1 2 4 3 4 5 6 7 8 9 10 -2 11 12 -3 1 2 3 4 5

Output-

5 4 3 2 1
10 9 8 7 6
12 11 5 4 3
End of file!
5 4 3 2 1 4 2 1

*/

int main()
{
    stack<int> s;

    int size;
    cin >> size;

    bool negative = false;
    while (size--)
    {
        int n;
        cin >> n;

        if (n < 0 && !negative)
        {
            int x = 5;
            if (s.size() < x)
            {
                cout << "ERROR: Stack has less than " << x << " items!" << endl;
                negative = true;
                continue;
            }
            while (x--)
            {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
            continue;
        }

        s.push(n);
    }

    cout << "End of file!" << endl;
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}