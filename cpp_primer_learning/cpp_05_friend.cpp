class A {
	friend class B;
public:
	int display() {
		return x;
	}
private:
	int x;
};

class B {
public:
	int display();
	void set_a(int);
private:
	A a;
};

int B::display() {
	return a.display();
}

void B::set_a(int x) {
	a.x = x;
}

/*
��Ԫ�ǵ���ġ�
��Ԫ��������Ǻ�����Ҳ�������ࡣ
*/