#include <iostream>
#include <set>
using namespace std;
main() {
	multiset <int> s;
	multiset <int> :: iterator it;
	int i;
	for (i=1;i<=5;i++) 
		s.insert(i*10); // s={10,20,30,40,50}
	s.insert(30); // s={10,20,30,30,40,50}
	cout << s.count(30) << endl; // In ra 2
	cout << s.count(20) << endl; // In ra 1
	s.erase(30); // s={10,20,40,50}
	/* Duyet set */
	for (it=s.begin();it!=s.end();it++) {
			cout << *it << " ";
	}
	// In ra 10 20 40 50
	cout << endl;
	system("pause");
}