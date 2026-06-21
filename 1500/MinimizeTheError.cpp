#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
 
using namespace std;
 
int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
 
    int totalOperations = k1 + k2;
 
    vector<long long> a(n), b(n);
 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    priority_queue<long long> maxHeap;
 
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        long long diff = llabs(a[i] - b[i]);
        maxHeap.push(diff);
    }
 
    while (totalOperations > 0)
    {
        long long current = maxHeap.top();
        maxHeap.pop();
 
        current = llabs(current - 1);
        maxHeap.push(current);
 
        totalOperations--;
    }
 
    long long answer = 0;
    while (!maxHeap.empty())
    {
        long long value = maxHeap.top();
        maxHeap.pop();
        answer += value * value;
    }
 
    cout << answer << endl;
 
    return 0;
}
