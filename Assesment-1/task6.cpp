#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool running = true;
    stack<int> inputStack, outputStack;
    queue<int> inputQueue, outputQueue;

    while (running)
    {
        cout << "1. Insert." << endl;
        cout << "2. Delete." << endl;
        cout << "3. Finish." << endl;

        int response;
        cin >> response;

        int n;
        switch (response)
        {
        case 1:
        {
            cout << "Insert element: ";
            cin >> n;
            inputStack.push(n);
            inputQueue.push(n);
            break;
        }
        case 2:
        {
            int stackDeleted = inputStack.top(), queueDeleted = inputQueue.front();
            inputStack.pop();
            inputQueue.pop();
            outputStack.push(queueDeleted);
            outputQueue.push(stackDeleted);
            break;
        }
        case 3:
        {
            cout << "Output stack: ";
            while (outputStack.size())
            {
                cout << outputStack.top() << " ";
                outputStack.pop();
            }
            cout << endl;
            cout << "Output queue: ";
            while (outputQueue.size())
            {
                cout << outputQueue.front() << " ";
                outputQueue.pop();
            }
            cout << endl;
            running = false;
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}