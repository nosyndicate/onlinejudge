//http://acm.hdu.edu.cn/showproblem.php?pid=1004
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> strvec;
	vector<string>::iterator it;
	string str,str_temp;
	int n;
	while(cin>>n && n != 0)
	{
		for(int i = 0;i < n;++i)
		{
			cin>>str;
			strvec.push_back(str);
		}
		int num,max = 0;
		vector<string>::iterator it1,it2;
		for(it1 = strvec.begin();it1 != strvec.end();++it1)
		{
			num = 1;
			for(it2 = it1 + 1;it2 != strvec.end();++it2)
				if(*it1 == *it2)
					++num;
			if(num > max)
			{
				max = num;
				str_temp = *it1;
			}
			//用泛型算法remove()就可以解决删除重复元素的问题了
			it = remove(it1+1,strvec.end(),*it1);
			strvec.erase(it,strvec.end());
		}
		cout<<str_temp<<endl;
		strvec.clear();
	}
	return 0;
}
