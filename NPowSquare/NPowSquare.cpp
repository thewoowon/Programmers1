// NPowSquare.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int quotient  = left / n + 1; // 몫 // 
    int remainder = left % n +1; // 나머지 // 실제위치의 값을 나타냄
    int quotientR = right / n + 1;
    int remainderR = right % n +1;
    //단순히 메모리 초과
    while (true)
    {
        if (quotient < quotientR)
        {
            if (remainder != 1) // 나머지는 1부터
            {
                if (remainder <= quotient) // 몫의 갑만큼 채우기 시작
                {
                    for (int i = remainder; i <= quotient; i++)
                    {
                        answer.push_back(quotient);
                    }
                    for (int i = quotient+1; i <= n; i++)
                    {
                        answer.push_back(i);
                    }
                }
                else // remainder부터 증가
                {
                    for (int i = remainder; i <= n; i++)
                    {
                        answer.push_back(i);
                    }
                }
            }
            else
            {
                for (int i = 0; i < quotient; i++)
                {
                    answer.push_back(quotient);
                }
                for (int i = quotient+1; i <= n; i++)
                {
                    answer.push_back(i);
                }
            }
        }
        else// 같은 라인
        {
            //같은 라인에 바로 떨어짐
            if (remainder != 1)
            {
                if (remainder != remainderR)
                {
                    for (int i = remainder; i <= remainderR; i++)
                    {
                        if (i <= quotient)
                        {
                            answer.push_back(quotient);
                        }
                        else
                        {
                            answer.push_back(i);
                        }
                    }
                    break;
                }
                else // 같으면 하나만 
                {
                    if (remainder <= quotient)
                    {
                        answer.push_back(quotient);
                    }
                    else
                    {
                        answer.push_back(remainder);
                    }
                    break;
                }
            }
            else
            {
                //이어진 경우
                if (remainderR <= quotient)
                {
                    for (int i = 0; i < remainderR; i++)
                    {
                        answer.push_back(quotient);
                    }
                    break;
                }
                else
                {
                    for (int i = 0; i < quotient; i++)
                    {
                        answer.push_back(quotient);
                    }
                    for (int i = quotient+1; i <= remainderR; i++)
                    {
                        answer.push_back(i);
                    }
                    break;
                }
            }
        }
        quotient += 1;
        remainder = 1; 
    }

    return answer;
}


int main()
{
    solution(10000000, 0, 1);
}