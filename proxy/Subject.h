#pragma once
#include <iostream>

using namespace std;

class Subject {
public:
	virtual void Create(string key, string value);
	virtual string Read(string key);
	virtual bool Update(string key, string value);
	virtual bool Delete(string key);
};

