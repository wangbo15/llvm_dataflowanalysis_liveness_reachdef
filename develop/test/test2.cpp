#include<iostream>
using namespace std;
template <class T>
class A{
	public:
		T a;
		A(): a(1) {}
};

template <class T>
void A::disp() {
	cout << "hello world\n";
}

