#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int result = INT_MAX;
void huisu(int day, vector<int>& v, int start, int time)
{
    if (day == 1)
    {
        int max_time = 0;
        int time_last = 0;
        for (int i = start; i < v.size(); i++)
        {
            time_last += v[i];
            if (v[i] > max_time)max_time = v[i];
        }
        time_last -= max_time;
        time_last = max(time, time_last);
        result = min(time_last, result);
        return;
    }
    for (int i = start; i < v.size(); i++)
    {
        int max_time = 0;
        int time_next = 0;
        for (int k = start; k <= i; k++)
        {
            time_next += v[k];
            if (v[k] > max_time)max_time = v[k];
        }
        time_next -= max_time;
        time_next = max(time, time_next);
        huisu(day - 1, v, i + 1, time_next);
    }
}
int main() {
    vector<int>v = { 1,2,2,3,5,4,6,7,8 };
    char c=5;
    huisu(c, v, 0, 0);
    cout << result;
}
// 64 位输出请用 printf("%lld")