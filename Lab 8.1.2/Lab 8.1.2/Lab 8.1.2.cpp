#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s, const char cs, const char	ks, int i)
{
	if ((cs == s[i] && ks== s[i+1])|| (ks == s[i] && cs == s[i + 1]))
		return true;
	if (s[i] != '\0')
		return Include(s, cs,ks, i + 1);
	else
		return false;
}
char* Change(char* dest, const char* s, char* t, int i)
{
	if (s[i + 1] != 0)
	{
		if ((s[i] == 'S' && s[i + 1] == 'Q')|| (s[i] == 'Q' && s[i + 1] == 'S'))
		{
			strcat_s(t,1, "***");
			return Change(dest, s, t + 3, i + 2);
		}
		else
		{
			*t++ = s[i++];
			*t = '\0';
			return Change(dest, s, t, i);
		}
	}
	else
	{
		*t++ = s[i++];
		*t++ = s[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char s[101];
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	char cs = 'S';
	char ks = 'Q';
	if (Include(s, cs, ks,0))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, s, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}