#pragma once
#include "Subject.h"

class RealSubject : Subject {
public:
	RealSubject();
	bool Update(string key, string value);
	bool Delete(string key)
};

