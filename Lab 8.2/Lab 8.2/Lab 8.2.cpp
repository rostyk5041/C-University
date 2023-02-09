#include <iostream>
#include <string>
#include "Lab 8.2.h"
using namespace std;
int Count(const char* s)
{
	int count = 0;
	for (int i=0 ; s[i] != '\0'; i++) 
	{
		if ((s[i] != ' ') && (s[i + 1] == ' '))
			count++;
	}
	return count;
}
int main()
{
	char s[101];
	cout << "Enter s:" << endl;
	cin.getline(s, 100);	cout <<"number of words="<< Count(s)+1 << endl;	return 0;
}