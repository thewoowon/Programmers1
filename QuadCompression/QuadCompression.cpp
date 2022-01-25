#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> chkPossible;
    vector<int> answer{0,0};
    int size = arr.size(); // 2의 거듭제곱값
    //size를 2로 나누면서 진행
    int divisor = 1; // 처음 시작은 -> 뭐든지
    while (true)
    {
        int share = arr.size() / divisor; // divisor로 계속 나누어 줍니다.
        for (int i = 0; i < divisor; i++) //이렇게 진행해도 될듯
        {
            for (int j = 0; j < divisor; j++)
            {
                bool comp = true;
                int now = -1;
                int pre = -1;
                for (int k = i * share; k < (i + 1) * share; k++)
                {
                    for (int l = j * share; l < (j + 1) * share; l++)
                    {
                        if (arr[k][l] == -1)                        
                            break;

                        if (now == -1 && pre == -1)
                        {
                            now = arr[k][l];
                            pre = arr[k][l];
                            continue;
                        }
                        else
                        {
                            now = arr[k][l];
                            if (pre != now)
                            {
                                comp = false;
                                break;
                            }
                        }

                        pre = now;
                    }
                    if (!comp)
                    {
                        break;
                    }
                }
                if (comp) // 모두가 맞다면
                {
                    if (now != -1)
                    {
                        answer[now] += 1;
                        for (int k = i * share; k < (i + 1) * share; k++)
                        {
                            for (int l = j * share; l < (j + 1) * share; l++)
                            {
                                arr[k][l] = -1;
                            }
                        }
                    }
                }
            }
        }
        divisor *= 2;
        if (arr.size() == divisor)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[i][j] == 0)
                        answer[0] += 1;
                    else if (arr[i][j] == 1)
                        answer[1] += 1;
                    else
                        continue;
                }
            }
            break;
        }
    }

    return answer;
}


int main()
{
    solution({ {1,1,1,1,1,1,1,1} ,{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}});
}

