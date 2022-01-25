#include <string>
#include <vector>
#include <bitset>
#include <cmath> // 2의 거듭제곱

using namespace std;


vector<string> bitMaker(int n)
{
    vector<string> bit;
    int clone = n; // 값 복사
    string result = "";
    //나머지가 0이하가 될때까지
    while (clone > 0)
    {
        if (clone % 2 == 1) // 
            bit.push_back("1");
        else
            bit.push_back("0");
        clone = clone / 2; // 몫을 할당     
    }
    return bit;
}

int counter(vector<string> bit)
{
    int count = 0;
    for (int i = 0; i < bit.size(); i++)
    {
        if (bit[i] == "1")
            count += 1;
    }
    return count;
}

int solution(int n) {
    int clone = n;
    vector<string> bit = bitMaker(n);
    int count = counter(bit);

    while (true)
    {
        clone += 1; // 1을 증가시키고
        vector<string> temp = bitMaker(clone); // 변환
        if (counter(temp) == count)
            return clone;
    }
}

int main()
{
    solution(78);
    return 0;
}