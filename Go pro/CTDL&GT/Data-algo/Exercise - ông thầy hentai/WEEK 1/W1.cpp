#include "Header.h"
#include <stdio.h>
#include <iostream>

using namespace std; //thu vien std

int linearSearch(int list[], int listLength, int key) {
	int loc = 0; //vi tri cua phan tu tim thay
	bool found = false; //flag de kiem tra la tim thay hay khong?
	
	//dung vong lap while
	//while (loc < listLength && !found) {
	//	if (list[loc] == key) found = true;
	//	else loc++;
	//}
	
	//dung vong lap for
	for (int i = 0; i < listLength; i++) {
		if (list[i] == key) {
			found = true;
			loc = i;
			exit; //thoat khoi vong lap for khi tim thay, khong can phai duyet phan tu tiep theo
		}
	}
	
	if (found) return loc; //tim thay
	else return -1; //khong tim thay
}

int binarySearch(int el, int left, int right, int a[]) {
	int mid = left;
	while (right >= left) {
		mid = (left + right) / 2;
		if (el == a[mid]) return mid;
		else if (a[mid] < el) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

#ifdef W1 
void main() {
	int n[] = {12, 16, 18, 27, 35, 38, 45} //khai bao mot mang so nguyen
	//int n[] = {35, 12, 27, 18, 45, 16, 38};
	
	int length = sizeof(n) / sizeof(n[0]); //tinh so phan tu cua mang
	
	//giai thuat tim kiem tuyen tinh
	//int result = linearSearch(n, length, 27);
	// cout << result;

	//giai thuat tim kiem nhi phan
	//cout << binarySearch(15, 0, length, n) << endl;
	//cout << binarySearch(27, 0, length, n) << endl

	//tinh tong cac phan tu trong mang
	int total = 0;
	for (int i = 0; i < length; i++) {
		total += n[i]; //tuc la tong = tong + n[i]
	}
	cout << total;
}
#endif // W1

