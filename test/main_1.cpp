
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// [ [1,2],[2,3],[3,4],[1,3] ]
// [ [1,2],[1,2],[1,2] ]
string& replace(string& src, const string& old_value, const string& new_value) {

	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;
}

std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

int str2int(string t1)
{
	stringstream ss;
	int t2;
	ss << t1;
	ss >> t2;
	return t2;
}

int main()
{
	string rim;
	string input;
	cin >> rim;
	cin >> input;
	cin >> rim;


	input = replace(input, "[", "");
	input = replace(input, " ", "");
	input = replace(input, "]", "");

	vector<std::string> inputs = split(input, ",");

	vector<vector<int>>  section;
	for (int i = 0; i < inputs.size() / 2; i++)
	{
		vector<int> temp;
		temp.push_back(str2int(inputs[i * 2]));
		temp.push_back(str2int(inputs[i * 2 + 1]));
		section.push_back(temp);
	}
	int res = 0;
	for (int i = 1; i < section.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (section[i][0] <= section[j][0] && section[i][1] <= section[j][1])
			{
				res++;
				break;
			}
		}
	}
	cout << res;
	


}


