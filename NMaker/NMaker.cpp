#include <iostream>
#include <string>
#include <vector>

using namespace std;

//진법으로 표현하기->
string nMaker(int n, int least)
{
    string result = ""; //단순히 string으로 이어 붙인다
    int iter = 0;
    while (result.length() < least)
    {
        string temp = "";
        int mok = iter;
        int leave;

        while (true)
        {
            leave = mok % n; // 몫을 나눈 나머지
            mok /= n;
            if (leave <=9) // 나머지가 9보다 작다면
                temp = to_string(leave) + temp; // 나눈 나머지를 주입
            else // 10보다 큰 수라면 
            {
                char ascii = leave + 55; // 아스키로 변환
                temp = ascii + temp; // 나눈 나머지를 주입
            }
            if (mok == 0)
                break;
        }
        result += temp; // 구한 temp를 이어 붙입니다.
        iter += 1;
    }   
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = nMaker(n, t * m);
    // m == p이면 -> 0
    // p < m이면 -> 나머지


    for (int  i = 1; i < temp.size()+1; i++)
    {
        if (m == p)
        {
            if (i % m == 0)
                answer += temp[i-1];
        }
        else
        {
            if (i % m == p)
                answer += temp[i-1];
        }
        if (temp.size() == t)
            break;
    }


    return answer;
}
int main()
{
    solution(16, 16, 2, 2);
}

