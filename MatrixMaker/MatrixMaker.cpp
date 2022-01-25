#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    //진행하면서 완전 탐색
    //한변의 길이는 최소 3이상
    //가로가 세로보다 크거나 같다
    int width = 3; // 최소 3에서 시작
    while (true)
    {
        int height = (brown - (2 * width)) / 2 + 2; // 높이의 값
        int realYellow = (width * height) - ((width * 2) + (height * 2) - 4); // 겉에 있는 테두리를 뺀값
        if (realYellow == yellow && width >= height)
        {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
        width += 1;
    }

    return answer;
}
int main()
{
    //10  2	    [4, 3]
    //8	  1     [3, 3]
    //24 24     [8, 6]
    solution(10,2);
    solution(8, 1);
    solution(24, 24);
}

