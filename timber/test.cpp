#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec(3);
	vec[0] = 1;

	for (auto x : vec)       // ���纻, ���� ���� �Ұ�
		x *= 2;

	for (auto& x : vec)      // ����, ���� ���� ����
		x *= 2;

	for (const auto& x : vec) // ��� ����, �б� ����
		std::cout << x << " ";
}