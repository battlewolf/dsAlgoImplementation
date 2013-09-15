#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
main () {
	char str[] = {"abcdefghij"};
	int len = strlen(str);
	for (int i = 1 ; i <= (1 << len) ; i++) {
		for (int j = len - 1 ; j >= 0 ; j--) 
			if (i & (1 << j)) cout << str[j];
		cout << endl ;
	}
}
