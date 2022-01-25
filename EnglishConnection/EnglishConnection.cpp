#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for (int i = 1; i < words.size(); i++) // 시작하는 단어는 신경쓰지 않아도 됨
    {
        //순서는 나머지 +1
        if (words[i][0] != words[i - 1][words[i - 1].size() - 1]) // 다르다면 바로 탈락
        {
            answer.push_back((i % n) + 1); // 순서
            answer.push_back((i / n) + 1); // 차례
            return answer;
        }
        //한번 쓴 단어라면
        for (int j = 0; j <i; j++)
        {
            if (words[j] == words[i])
            {
                answer.push_back((i % n) + 1); // 순서
                answer.push_back((i / n) + 1); // 차례
                return answer;
            }
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main()
{
    solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
}
