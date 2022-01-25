
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> time; // 시간만을 담는 벡터
    vector<int> total;
    int tag = 0;

    //다리의 길이가 곧 시간
    
    while (true)
    {
        int temp = 0;
        for (int i = 0; i < total.size(); i++)
            temp += total[i];
        if (truck_weights[tag] <= weight - temp)
        {
            time.push_back(1);
            total.push_back(truck_weights[tag]);
            answer += 1; //증가시켜줌
            tag += 1;
            for (int i = 0; i < time.size()-1; i++)
                time[i] += 1;
            continue;
        }
        for (int i = 0; i < time.size(); i++)
            time[i] += 1;
        if (time[0] == bridge_length) //마지막에 왔다면
        {
            time.erase(time.begin() + 0);
            total.erase(total.begin() + 0);
            continue;
        }
        answer += 1;
    }

    

    return answer;
}


int main()
{
    solution(2, 10, { 7,4,5,6 });
}

