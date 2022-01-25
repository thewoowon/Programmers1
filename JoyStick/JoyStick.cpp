#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, A
    // 65  ~  90  총 26 // 
    // 무조건 A에서 시작하기 때문에
    // 78보다 작으면 위쪽 
    // 크면 아래쪽
    // 78이면 그냥 아무곳

    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] < 78)
            answer += name[i] - 65;
        else if(name[i] > 78)
            answer += 91 - name[i];
        else // 78이면
            answer += 13;
    }

    int id = 0; // 인덱스를 담는 
    int count = 0;
    int limit = name.size() - 1; // 왜냐하면 그냥 가는 것보다 짧아야하므로
    int alphaStartId; //  A의 아이디를 저장 // 연속되는 크기
    int alphaEndId; //  A의 아이디를 저장 // 연속되는 크기
    int alphaLength; // A의 길이를 담을 변수

    if (name[name.size()-1] == 'A') // 마지막에 A가 있다면
    {
        int tempCount = 1;
        int tempId = name.size() - 1;
        while (tempId > 0) // 처음은 상관이 없어서
        {
            tempId -= 1;
            if (name[tempId] == 'A')
            {
                tempCount += 1;
                tempId -= 1;
            }
            else
            {
                tempId += 1; // 마지막 A
                break;
            }
        }
        limit = name.size() - tempCount - 1;
    }

    while (true) // 찍고 돌아온다
    {
        id += 1; // 오른쪽 먼저 진행
        if (name[id] == 'A')
        {
            alphaStartId = id;
            while (true)
            {
                // A가 연속되었는지 아닌지 조사
                id += 1;
                if (name[id] == 'A') // 이어진다면
                {
                    alphaEndId = id;
                    alphaLength = id - alphaStartId + 1; //
                }
                else {
                    alphaEndId = id - 1;
                    alphaLength = alphaEndId - alphaStartId + 1; //
                    id = 0; // 처음으로 회귀
                    break; // 탈출
                }
            }
            if (((alphaStartId-1) * 2) + 1 <= alphaLength+1 && id == 0) //ㅛㅛㅛ
            {
                int total = name.size() - alphaEndId - 2 + (alphaStartId-1) * 2 +1;
                if (total <= limit)
                {
                    answer += total;
                    break;
                }
                else {
                    answer += limit;
                    break;
                }


                //
            }
            else
            {
                answer += limit;
                break;
            }
        }
        else
        {
            if (id == name.size()-1) // 마지막에 왔다면 // A가 없어서
            {
                answer += name.size() - 1; 
                break;
            }
        }
    }
    return answer;
}


int main()
{
    solution("BBBBAABBB");
}
