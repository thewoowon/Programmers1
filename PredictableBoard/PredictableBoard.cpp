// PredictableBoard.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다

#include <iostream>
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (true)
    {
        if (a < b)
        {
            if (b % 2== 0 && b - a ==1)
            {
                answer += 1;
                //same boundary
                break;
            }
        }
        else // 2의 지수승으로 주어지기 때문에 같을 수가 없다
        {
            if (a % 2 == 0 && a - b == 1)
            {
                answer += 1;
                //same boundary
                break;
            }
        }
        if (a % 2 ==0)
            a /= 2;
        else
            a = a /2 +1;

        if (b % 2 == 0)
            b /= 2;
        else
            b = b / 2 +1;

        answer += 1;
    }
    return answer;
}

int main()
{
    solution(16, 15, 1);
}