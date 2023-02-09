#include <iostream>
#include <string>
using namespace std;
string Change(string& s)
{
	size_t pos = 0;
	while ((pos = s.find('S', pos)) != -1)
		if (s[pos + 1] == 'Q')
			s.replace(pos, 2, "***");
	return s;
}
int main()
{
	string s;
	cout << "Enter string:" << endl;
	getline(cin, s);
	
	string cs = "SQ";
	string ks = "QS";

	if ((s.find(cs) != -1) || (s.find(ks) != -1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	string dest = Change(s);
	cout << "Modified string (param) : " << s << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}