#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int total = 5 * 6 * 6 * 6 * 6; // 총 가지수
    // 'A', 'E', 'I', 'O', 'U'
    // 단어당 5 * 6 * 6 * 6 * 6 -> 5가지를 뽑는 경우의 수
    // 미리 단어집을 만들어 놓고 찾는다
    // 해당 단어를 문자별로 나누면서 
    for (int i = 0; i < word.size(); i++) // 해당 문자열의 사이즈로 
    {
        if (word[i] =='A') // 개별마다
        {

        }
        else if (word[i] == 'E')
        {

        }
        else if (word[i] == 'I')
        {

        }
        else if (word[i] == 'O')
        {

        }
        else if (word[i] == 'U')
        {

        }
    }


    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}