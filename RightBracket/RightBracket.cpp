#include <iostream>
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true; // 올바른 괄호를 찾는 -> 닫혀야만 한다
    int left = 0;
    int right = 0;

    //올바른 괄호는 항상 '('의 개수가 '('의 개수와 같거나 커야함

    for (int i = 0; i < s.size(); i++) // 해당 문자열 반복문
    {
        if (s[i] == '(' )
            left += 1; 
        else
            right += 1;

        if (right > left)
            return false;
        
        if (s.size() - 1 == i && right != left) // 끝에 왔을 때
            return false;
    }

    return answer;
}


int main()
{
    std::cout << "Hello World!\n";
}