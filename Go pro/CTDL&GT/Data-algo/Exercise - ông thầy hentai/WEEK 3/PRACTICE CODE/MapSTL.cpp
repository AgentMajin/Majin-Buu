#include <iostream>
#include <map>
#include <vector>
using namespace std;
main() {
	map <char,int> m;
	map <char,int> :: iterator it;
	m['a']=1; 							// m={{'a',1}}
	m.insert(make_pair('b',2)); 		// m={{'a',1};{'b',2}}
	m.insert(pair<char,int>('c',3) ); 	// m={{'a',1};{'b',2};{'c',3}}
	cout << m['b'] << endl; 			// In ra 2
	m['b']++; 							// m={{'a',1};{'b',3};{'c',3}}
	it=m.find('c'); 					// it point to key 'c'
	cout << it->first << endl; 			// In ra 'c'
	cout << it->second << endl; 		// In ra 3
	m['e']=100; 						// m={{'a',1};{'b',3};{'c',3};{'e',100}}
	it=m.lower_bound('d'); 				// it point to 'e'
	cout << it->first << endl; 			// In ra 'e'
	cout << it->second << endl; 		// In ra 100
	system("pause");
}
