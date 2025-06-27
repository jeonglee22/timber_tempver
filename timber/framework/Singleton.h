#pragma once

template<typename T>
class Singleton
{
protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// delete를 넣어주면 아예 사용을 할 수 없게 만든다. (컴파일 에러)
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

public:
	static T& Instance()
	{
		// static 지역 변수
		// 일반 변수와 다르게 프로그램 시작과 끝에 생성되고 사라진다.
		static T instance;
		return instance;
	}

};