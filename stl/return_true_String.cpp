#include<iostream>
#include<cstring>
#include<set>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
 int l = strlen(str);
 string result;
 char ch;
set<char> s;
for(int i=0;i<l;i++)
{
	ch = str[i];
	if(s.find(ch)==s.end())
	{
		result.push_back(ch);
		s.insert(ch);
	}
 }
 char outpur[1000000];
 strcpy(outpur,result.c_str()) ;
 return outpur;
 
 }
int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}


