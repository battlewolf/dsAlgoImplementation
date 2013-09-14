#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

/*Templates*/
#define INF 1<<32
#define PI 3.141592653589793
#define AND &&
#define OR || 
#define NOT !
#define all(c) c.begin(),c.end()
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(all(container),element) != container.end())
#define ins insert
#define sz size
#define pb push_back
#define pp pop
#define v(data) vector<data>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vs vector<string>
#define mp make_pair()
#define pi pair<int, int>
#define vpi v(pi)
#define matrix(data) vector<vector<data> > 
#define FOR(i,end,begin) for(int i=start; i <= end; i++)
#define TR(c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define REP(i,end) for(int i = 0 ; i < end; i++)
//#define MAX 1000

using namespace std;
vi nodes;
vector<pair<int,int> >  links;
int find(int);

void init() {
	int n = nodes.size();
	REP(i,n) {
		nodes[i] = i;
//		links[i].first stores the links to proceed in the tree
// 		links[i].second stores the number of nodes of the tree
		links[i].first = i;
		links[i].second = 1;
	}
}

void merge(int node1, int node2) {
/* If both the nodes are in the same tree, then no need of merge*/
	int root1, root2;
	if ((root1 = find(node1)) != (root2 = find(node2))) {
		if(links[root1].second <= links[root2].second) {
			links[root1].first = root2;
			links[root2].second = links[root2].second + links[root1].second;
		}
		else {
			links[root2].first = root1;
			links[root1].second = links[root1].second + links[root2].second;
		}
	}
	
}

int find(int node) {
	/* Start from the node and proceed till the root*/
	while( nodes[node] != links[node].first) {
		node = links[node].first;
	}
	return node;

}

main() {
	int n;
	cin >> n;

	nodes.resize(n);
	links.resize(n);
	init();
	merge(1,2);
	merge(2,3);
	merge(4,5);
	merge(4,1);
	REP(i,n) 
	
		cout << endl << links[i].first << " " << links[i].second;
	
	
}























