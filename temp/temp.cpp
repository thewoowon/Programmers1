#include <string>
#include <vector>

using namespace std;

 vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>());
        
    // 행렬의 곱은 왼쪽에서 오른쪽으로 진행
    // 행수와 열의 수는 일치해야한다.
    // 이중 for
    for (int i = 0; i < arr1.size(); i++) //왼쪽 행렬을 완전히 탐색
    {
        for (int j = 0; j < arr2[0].size(); j++) // 
        {
            int total = 0;
            for (int k = 0; k < arr1[i].size(); k++) // 입력받은 행의 모든 탐색
            {
                int temp = arr1.at(i).at(k) * arr2.at(k).at(j);
                total += temp;
            }
            answer.at(i).push_back(total); // 내부의 벡터에 주입
        }
    }
   
    return answer;
}

int main()
{
    vector<vector<int>> temp1 = { {2, 3, 2},{4, 2, 4},{3, 1, 4} }; 
    vector<vector<int>> temp2 = { {5, 4, 3},{2, 4, 1},{3, 1, 1} };
    
    solution(temp1, temp2);

    return 0;
}