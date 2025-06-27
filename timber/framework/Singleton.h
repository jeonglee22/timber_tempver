#pragma once

template<typename T>
class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// delete�� �־��ָ� �ƿ� ����� �� �� ���� �����. (������ ����)
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

public:
	static T& Instance()
	{
		// static ���� ����
		// �Ϲ� ������ �ٸ��� ���α׷� ���۰� ���� �����ǰ� �������.
		static T instance;
		return instance;
	}

};