#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;


class Lock {
public:
	explicit Lock(mutex* pm) : 
		mutexPtr(pm) {
		mutexPtr->lock();
	}
	~Lock() {
		mutexPtr->unlock();
	}
private:
	shared_ptr<mutex> mutexPtr;
};



class Pretty;
class Image {
	friend void lookBackground(Pretty& p);
public:
	Image(string color):m_color(color){}
private:
	string m_color{ "green" };
};

struct PMImpl {
	shared_ptr<Image> bgImage;
	int imageChanges;
};

class Pretty {
	friend void lookBackground(Pretty& p);
public:
	void changeBackground(string s);
private:
	mutex m;
	shared_ptr<PMImpl> pImpl;
};
void Pretty::changeBackground(string color) {
	using std::swap;
	Lock m1(&m);
	shared_ptr<PMImpl> pNew=make_shared<PMImpl>();

	pNew->bgImage.reset(new Image(color));                                                        
	++pNew->imageChanges;
	swap(pImpl, pNew);
}

void lookBackground(Pretty& p) {
	cout << "color:" << p.pImpl->bgImage->m_color << endl;
}

int main() {                                                                                     
	Pretty p;
	lookBackground(p);
	p.changeBackground(string("blue"));
	lookBackground(p);

	system("pause");
	return 0;
}