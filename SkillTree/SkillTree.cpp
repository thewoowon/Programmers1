#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        std::string::size_type tempPre = 0;
        std::string::size_type tempNow = 0;
        for (int j = 0; j < skill.size(); j++)
        {
            tempNow = skill_trees[i].find(skill[j], 0);
            if (tempNow == std::string::npos) {
                bool check = true;
                for (int k = j+1; k < skill.size(); k++)
                {
                    std::string::size_type t = skill_trees[i].find(skill[k], 0);
                    if (t != std::string::npos)
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                {
                    break;
                }
                else
                {
                    answer += 1;
                    break;
                }

            }
            if (tempNow < tempPre) // 이전이 더 크다면
                break;
            if (j == skill.size()-1)
            {
                answer += 1;
                break;
            }
            tempPre = tempNow;
        }
    }


    return answer;
}
int main()
{
    solution("CBD", { "XYZRC", "QZTRCB", "CBDASF", "WERCG" });
}


