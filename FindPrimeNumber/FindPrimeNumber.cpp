#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int countD = 0; // 전역으로
bool visit[9999999] = {false,};// 7개의 수가 전부 9일 경우


void checkPrime(int number,int& answer)
{
    if (number < 2)return;
    int a = (int)sqrt(number);
    for (int i = 2; i <= a; i++) {
        if (number % i == 0)
            return;
    }
    if (!visit[number])
    {
        visit[number] = true;
        answer += 1;
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<char> vec;

    for (int i = 0; i < numbers.size(); i++)
    {
        vec.push_back(numbers[i]);
    }

    sort(vec.begin(), vec.end());
    do {
        string temp = "";
        for (int i = 0; i < vec.size(); i++)
        {
            temp += vec[i];
            checkPrime(stoi(temp), answer);
        }

    } while (next_permutation(vec.begin(), vec.end()));

    return answer;
}

int main()
{
    cout << solution("17") << endl;
    return 0;
}