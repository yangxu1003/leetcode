#include <iostream>
#include <vector>

using namespace std;

template <size_t N> 
class bitset
{
public:
	bitset()
	{
		_bits.resize((N >> 3) + 1, 0);//  N/8 + 1
	}

	//左边高位  右边低位
	void set(size_t x)//设为1
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] |= (1 << num);
	}

	void reset(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] &= (~(1 << num));
	}

	bool test(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bits[index] & (1 << num);
	}

private:
	vector<char> _bits;
	// vector<int> _bits;
};

void testbitset()
{
	bitset<100> bs;
	bs.set(10);
	bs.set(17);
	bs.set(80);
	
	cout << bs.test(10) << endl;
	cout << bs.test(17) << endl;
	cout << bs.test(80) << endl;
	cout << bs.test(81) << endl;

	bs.reset(80);
	bs.set(81);

	cout << bs.test(10) << endl;
	cout << bs.test(17) << endl;
	cout << bs.test(80) << endl;
	cout << bs.test(81) << endl;
}

int main()
{
	testbitset();

	bitset<-1> bs_max;
	return 0;
}