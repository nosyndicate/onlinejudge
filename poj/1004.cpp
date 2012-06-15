/*easy problem*/

#include <iostream>
using namespace std;


int main()
{
    int t = 12;
    double sum = 0, single;
    while(t--)
    {
	cin >> single;
	sum+=single;	
    }
    cout << "$" << sum/12 <<endl;
    return 0;    
}
