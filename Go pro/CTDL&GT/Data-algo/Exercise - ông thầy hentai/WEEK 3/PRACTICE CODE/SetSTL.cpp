#include <iostream>
#include <set>
using namespace std;
main() {
	set <int> s;
	set <int> ::iterator it;
	s.insert(9); 				// s={9}
	s.insert(5); 				// s={5,9}
	cout << *s.begin() << endl; //In ra 5
	s.insert(1); 				// s={1,5,9}
	cout << *s.begin() << endl; // In ra 1
	it=s.find(5);
	if (it==s.end()) cout << "Khong co trong container" << endl;
	else cout << "Co trong container" << endl;
	s.erase(it); 			// s={1,9}
	s.erase(1); 			// s={9}
	s.insert(3); 			// s={3,9}
	s.insert(4); 			// s={3,4,9}
	it=s.lower_bound(4);
	if (it==s.end()) cout << "Khong ton tai phan tu khong be hon 4" << endl;
	else cout << "Phan tu be nhat khong be hon 4 la " << *it << endl; // In ra 4
	it=s.lower_bound(10);
	if (it==s.end()) cout << "Khong ton tai phan tu khong be hon 10" << endl;
	else cout << "Phan tu be nhat khong be hon 10 la " << *it << endl; // Khong co
	it=s.upper_bound(4);
	if (it==s.end()) cout << "Khong co phan tu nao trong set lon hon 4" << endl;
	else cout << "Phan tu be nhat lon hon 4 la " << *it << endl; // In ra 9
	/* Duyet set */
	for (it=s.begin();it!=s.end();it++) {
		cout << *it << " ";
	}
	// In ra 3 4 9
	cout << endl;
	system("pause");
}
