#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


long long calcMaker(string v, vector<char> c)
{
    long long answer = 0;

    for (int i = 0; i < c.size(); i++)
    {
        bool yn = true;
        while (yn)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] == c[i])
                {
                    string left = "";
                    string right = "";
                    int leftId = -1;
                    int rightId = v.size() - 1;
                    //이때 인덱스를 기준으로 좌우를 조사
                    for (int k = j - 1; k >= 0; k--) // 감소방향
                    {
                        if (v[k] == '_') {
                            left = "-" + left;
                            break;
                        }

                        if (v[k] != '*' && v[k] != '+' && v[k] != '-') // 
                        {
                            left = v[k] + left;
                        }       
                        else
                        {
                            leftId = k;
                            break;
                        }
                    }
                    for (int k = j + 1; k < v.size(); k++) // 증가방향
                    {
                        if (v[k] == '_' && k == j+1)
                        {
                            right += "-";
                            continue;
                        }
                        if (v[k] != '*' && v[k] != '+' && v[k] != '-') // 
                        {
                            right += v[k];
                            if (k == v.size() - 1)
                            {
                                rightId = k + 1;
                                break;
                            }
                        }
                        else
                        {
                            rightId = k;
                            break;
                        }
                    }

                    if (v[j] == '*')
                    {
                        long long temp = stoll(left) * stoll(right);
                        if (temp < 0)
                        {
                            v = v.substr(0, leftId + 1) + "_" + to_string(std::abs(temp)) + v.substr(rightId, v.size() - rightId);
                        }
                        else
                        {
                            v = v.substr(0, leftId + 1) + to_string(temp) + v.substr(rightId, v.size() - rightId);
                        }
                    }
                    else if (v[j] == '+')
                    {
                        long long temp = stoll(left) + stoll(right);
                        if (temp < 0)
                        {
                            v = v.substr(0, leftId + 1) + "_" + to_string(std::abs(temp)) + v.substr(rightId, v.size() - rightId);
                        }
                        else
                        {
                            v = v.substr(0, leftId + 1) + to_string(temp) + v.substr(rightId, v.size() - rightId);
                        }
                    }
                    else
                    {
                        long long temp = stoll(left) - stoll(right);
                        if (temp < 0)
                        {
                            v = v.substr(0, leftId + 1) + "_" + to_string(std::abs(temp)) + v.substr(rightId, v.size() - rightId);
                        }
                        else
                        {
                            v = v.substr(0, leftId + 1) + to_string(temp) + v.substr(rightId, v.size() - rightId);
                        }
                    }
                    break;
                }

                if (j == v.size() - 1)
                {
                    yn = false;
                    break;
                }
            }
        }
        //다음 우선순위로 넘어가는 단계
    }


    if (v[0] == '_')
    {
        answer = stoll(v.substr(1,v.size()-1));
    }
    else
    {
        answer =  std::abs(stoll(v));
    }
    return answer;
}



long long solution(string expression) {
    long long answer = -1;

    vector<char> operatorV{ '*','+','-' };

    do
    {
        answer = std::max<long long>(calcMaker(expression, operatorV), answer);

    } while (next_permutation(operatorV.begin(), operatorV.end())); // 현재와 처음이 존재한다면

    return answer;
    //1248000
}

int main()
{
    //100 - 200 * 300 - 500 + 20
    //solution("0*0*7+1-999");
    solution("2*2*2*2*2-2*2*2");

}
