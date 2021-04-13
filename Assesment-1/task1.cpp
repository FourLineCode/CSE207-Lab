#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;

    int *list1 = (int *)malloc(m * sizeof(int));
    int *list2 = (int *)malloc(m * sizeof(int));
    int *list3 = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        cin >> list1[i];
    for (int i = 0; i < m; i++)
        cin >> list2[i];
    for (int i = 0; i < m; i++)
        list3[i] = list1[i] > list2[i] ? list1[i] : list2[i];

    for (int i = 0; i < m; i++)
        cout << list3[i] << " ";
    cout << endl;
}