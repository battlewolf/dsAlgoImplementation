/*Printing all the permutations of a string recursively*/

#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> S;
void printPerm(string &s, int i)
{
		  if(i == s.size())
		  {
		  			 S.insert(s);	 
		//			 cout << s << endl ;
					 return;
		  }
		  for(int loop = i; loop < s.size(); loop++)
		  {
					 swap(s[i], s[loop]);
					 printPerm(s, i+1);
					 swap(s[i], s[loop]);
		  }

}

main()
{
		  string str = "abcdefghijklm";
		  printPerm(str, 0);

		  //for(set<string>::iterator it = S.begin(); it != S.end(); it++)
		  	//		cout << endl << *it;

			cout << endl << S.size();
}
