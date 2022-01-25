#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> vec;
    //가장 오랫동안 참조되지 않은 것들은 제일 위에 
    //시간을 체크해야함 -> 큰 오버헤드가 발생

    if (cacheSize == 0)
        return  5 * cities.size();
   

    for (int i = 0; i < cities.size(); i++)
    {
        string lowerCase = "";
        for (int j = 0; j < cities[i].size(); j++)
        {
            lowerCase += tolower(cities[i][j]);
        }

        if (vec.size() == cacheSize)
        {
            auto pt = find(vec.begin(), vec.end(), lowerCase);
            if (pt != vec.end())
            {
                vec.erase(pt, pt+1);
                vec.push_back(lowerCase);
                answer += 1;
            }
            else {
                vec.erase(vec.begin(), vec.begin()+1);
                vec.push_back(lowerCase);
                answer += 5;
            }
            //있나 없나 확인 -> 이미 캐시에 존재한다면 참조 히트 +1 and 제일 뒤로 뺀다

        }
        else
        {
            auto pt = find(vec.begin(), vec.end(), lowerCase);
            if (pt != vec.end())
            {
                vec.erase(pt, pt + 1);
                vec.push_back(lowerCase);
                answer += 1;
            }
            else {
                vec.push_back(lowerCase);
                answer += 5;
            }
        }
    }


    return answer;
}

int main()
{
    solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });

    //캐시 히트[Cache Hit]란 ?

    //CPU가 참조하고자 하는 메모리가 캐시에 존재하고 있을 경우 Cache Hit라고 한다.
    //참조하고자 하는 메모리가 있는 경우 실행시간은 1


    //캐시 미스[Cache Miss]란 ?

    //CPU가 참조하고자 하는 메모리가 캐시에 존재하지 않을 때 Cache Miss라고 한다.
    //참조하고자 하는 매모리가 없는 경우 실행시간은 5

        /*3["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	50
        3["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]	21
        2["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	60
        5["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	52
        2["Jeju", "Pangyo", "NewYork", "newyork"]	16
        0["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	25*/
}

