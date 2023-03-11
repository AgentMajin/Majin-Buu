#include <iostream>
#include <set>
#include <vector>
using namespace std;
main() {
	set <int, greater <int> > s;
	set <int, greater <int> > :: iterator it; // Phép toán so sánh là greater
	s.insert(1); // s={1}
	s.insert(2); // s={2,1}
	s.insert(4); // s={4,2,1}
	s.insert(9); // s={9,4,2,1}
	/* Tim phần tử lớn nhất bé hơn hoặc bằng 5 */
	it=s.lower_bound(5);
	cout << *it << endl; // In ra 4
	/* Tim phần tử lớn nhất bé hơn 4 */
	it=s.upper_bound(4);
	cout << *it << endl; // In ra 2
	system("pause");
}