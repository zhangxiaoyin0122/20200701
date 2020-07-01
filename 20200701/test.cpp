#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	string ptr;
	string ret;
	int length = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			ptr += str[i];
			while (str[i + 1] >= '0' && str[i + 1] <= '9') {
				ptr += str[i + 1];
				i++;
			}
			if (ptr.size() > length) {
				length = ptr.size();
				ret = ptr;
			}
		}
		ptr.clear();
	}
	cout << ret << endl;
	return 0;
}

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		/*if(numbers.empty())
			return 0;
		sort(numbers.begin(),numbers.end());
		int mid = numbers[numbers.size()/2];
		int count = 0;
		for(int i = 0;i < numbers.size();++i){
			if(numbers[i] == mid)
				count++;
		}
		if(count > numbers.size()/2)
			return mid;
		return 0;
	}*/
		int ret = numbers[0];
		int count = 1;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == ret)
				count++;
			else {
				count--;
			}
			if (count == 0) {
				ret = numbers[i];
				count = 1;
			}
		}
		count = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == ret)
				count++;
		}
		return count > numbers.size() / 2 ? ret : 0;
	}
};
