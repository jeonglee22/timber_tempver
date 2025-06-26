#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec(3);
	vec[0] = 1;

	for (auto x : vec)       // 복사본, 원본 수정 불가
		x *= 2;

	for (auto& x : vec)      // 참조, 원본 수정 가능
		x *= 2;

	for (const auto& x : vec) // 상수 참조, 읽기 전용
		std::cout << x << " ";
}