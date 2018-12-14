#include <iostream>
using namespace std;

int k=0;
void removeConsecutiveDuplicates(char *input, int shift=0) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	if(input[0]=='\0')
    {
      input[0-shift] = input[0];k++;
      input[k]='\0';
      return;
    }
   if(input[0]==input[1])
   {
    removeConsecutiveDuplicates(input+1, shift+1);
   }
  else
  {
     input[0-shift] = input[0];k++;
     removeConsecutiveDuplicates(input+1, shift);
  }
    

}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
