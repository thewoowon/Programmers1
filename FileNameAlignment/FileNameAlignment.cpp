
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>



using namespace std;

typedef map<string, string> ss;


map<string, string> maker(string target,int index)
{
	map<string, string> mapper;
	vector<string> vHead;
	vector<string> vHeadL;
	vector<string> vNumber;
	vector<string> vTail;

	string head;
	string headL;
	string number;
	string tail;
	int step = 0;
	head += target[0];
	headL += tolower(target[0]);
	for (int i = 1; i < target.size(); i++)
	{
		if (step == 0)
		{
			if (target[i] >= 48 && target[i] <= 57)
			{
				number += target[i];
				step = 1;
				vHead.push_back(head);
				vHeadL.push_back(headL);
			}
			else
			{
				head += target[i];
				headL += tolower(target[i]);
			}
		}
		else if (step == 1)
		{
			if (target[i] >= 48 && target[i] <= 57)
			{
				number += target[i];
			}
			else
			{
				tail += target[i];
				step = 2;
				vNumber.push_back(number);
			}
		}
		else
		{
			tail += target[i];
		}
	}
	mapper.insert(make_pair("HEAD", head));
	mapper.insert(make_pair("HEADL", headL));
	mapper.insert(make_pair("NUMBER", number));
	mapper.insert(make_pair("NUMBERO", number));
	mapper.insert(make_pair("TAIL", tail));
	mapper.insert(make_pair("INDEX", to_string(index)));

	return mapper;
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
	vector<map<string, string>> mapper;
	for (int i = 0; i < files.size(); i++)
	{
		 mapper.push_back(maker(files[i],i));
	}

	sort(mapper.begin(), mapper.end(), [](ss a, ss b)-> bool {
		if(a["HEADL"] == b["HEADL"]) 
		{
			if(stoi(a["NUMBER"]) == stoi(b["NUMBER"]))
				return stoi(a["INDEX"]) > stoi(b["INDEX"]);
			else
				return stoi(a["NUMBER"]) > stoi(b["NUMBER"]);
		} 
		else
		{
			return a["HEADL"] > b["HEADL"];
		}
	});

	reverse(mapper.begin(), mapper.end());

	for (int i = 0; i < mapper.size(); i++)
	{
		string temp = mapper[i]["HEAD"] + mapper[i]["NUMBER"] + mapper[i]["TAIL"];
		answer.push_back(temp);
	}


    return answer;
}

int main()
{
	solution({"A-010 Thunderbolt II","F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
}
