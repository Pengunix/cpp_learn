#include <vector>

class FooVec
{
public:
	std::vector<int> m_vec;
 
	FooVec(std::initializer_list<int> list)
	{
		for (auto it = list.begin(); it != list.end(); it++)
			m_vec.push_back(*it);
	}
};
 
int main(int argc, char * argv[])
{
	FooVec foo1 { 1, 2, 3, 4, 5, 6 };
	FooVec foo2 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	return 0;
}