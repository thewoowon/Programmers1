#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> Split(string str, char c);

string totalString(string s, string e, string scale)
{
    // 시작시간과 끝나는 시간사이의 분을 구한다
    // 해당 시간에 스트리밍된 음악의 string을 구한다.
    string result = "";
    vector<string> start = Split(s, ':');
    vector<string> end = Split(e, ':');
    vector<string> pallete;
    int startTotal = (stoi(start[0]) * 60) + stoi(start[1]);
    int endTotal = (stoi(end[0]) * 60) + stoi(end[1]);
    int diff = endTotal - startTotal;

    for (int i = 0; i < scale.size(); i++)
    {
        string temp;
        temp += scale[i];
        if (i != scale.size() - 1)
        {
            if (scale[i + 1] == '#')
            {
                temp += '#';
                i += 1;
            }
        }
        pallete.push_back(temp);
    }


    for (int i = 0; i < diff; i++)
    {
        int divisor = i % pallete.size();
        result += pallete[divisor];
    }
    return result;
}


vector<string> Split(string str, char c)
{
    vector<string> vec;

    istringstream ss(str);
    string stringBuffer;
    while (getline(ss, stringBuffer, c))
    {
        vec.push_back(stringBuffer);
    }

    return vec;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<vector<int>> vec(musicinfos.size(), vector<int>(4));
    vector<string> rVec;
    vector<int> iVec;
    vector<string> tVec;
    // m은 내가 기억한 멜로디
    // C, C#, D, D#, E, F, F#, G, G#, A, A#, B -> 12ea
    // 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보
    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector<string> vec = Split(musicinfos[i], ',');
        string result = totalString(vec[0], vec[1], vec[3]);
        if (result.size() >= m.size() && result.find(m) != string::npos)
        {
            int off = 0;
            bool sw = true;
            while (result.find(m,off) != string::npos)
            {
                int sharpCheck = result.find(m,off) + m.size(); // 
                if (result[sharpCheck] == '#') // 
                {
                    off = sharpCheck;
                    sw = false;
                }
                else {
                    sw = true;
                    break;
                }
            }
            if (!sw)
                continue;
            rVec.push_back(vec[2]);
            iVec.push_back(result.size());
            tVec.push_back(vec[0]);
        }
    }
    //길이가 더 긴것, 먼저 입력된 것
    int rMax = 0;
    int indexIVec = 0;

    if (rVec.size() > 0)
    {
        for (int i = 0; i < rVec.size(); i++)
        {
            int len = iVec[i]; // 
            if (rMax == len)
            {
                continue;
            }
            else if (rMax < len)
            {
                rMax = len;
                indexIVec = i;
            }
        }
        answer = rVec[indexIVec];
    }
    else {
        answer = "(None)";
    }
    return answer;
}

int main()
{
    solution("CCB", { "03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC" });
}
