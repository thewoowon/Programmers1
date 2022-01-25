#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 5;
#define MIN -5;


bool finder(vector<vector<int>> trace, vector<int> now, vector<int> pre)
{
    for (int i = 0; i < trace.size(); i++)
    {
        if (trace[i][0] == now[0] && trace[i][1] == now[1])
        {
            if (i > 0 && trace[i-1][0] == pre[0] && trace[i-1][1] == pre[1]) {
                //일치한다면
                return false;
            }
        }
    }
    reverse(trace.begin(), trace.end());
    for (int i = 0; i < trace.size(); i++)
    {
        if (trace[i][0] == now[0] && trace[i][1] == now[1])
        {
            if (i > 0 && trace[i - 1][0] == pre[0] && trace[i - 1][1] == pre[1]) {
                //일치한다면
                return false;
            }
        }
    }
    return true;
}

int solution(string dirs) {
    int answer = 1;
    vector<vector<int>> trace{ {0,0} }; //  처음 위치 초기화
    vector<int> now{ 0,0 }; // 처음 위치 초기화
    vector<int> pre{ 0,0 };

    for (int i = 0; i < dirs.size(); i++)
    {
        switch (dirs[i])
        {
            case 'U':
                if(now[1] < 5)
                    now[1] += 1;
                else
                    continue;
                break;
            case 'D':
                if(now[1] > -5)
                    now[1] -= 1;
                else
                    continue;
                break;
            case 'R':
                if(now[0] < 5)
                    now[0] += 1;
                else
                    continue;
                break;
            case 'L':
                if (now[0] > -5)
                    now[0] -= 1;
                else
                    continue;
                break;
        }
        if (i > 0 && finder(trace, now, pre)) {
            answer += 1;
        }
        trace.push_back(now);
        pre[0] = now[0];
        pre[1] = now[1];
    }
    // U D L R
    // 상하좌우 5 5

    return answer;
}
int main()
{
    solution("LULLLLLLU");
}
