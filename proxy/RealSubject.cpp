#include "RealSubject.h"
#include <map>

RealSubject::RealSubject() {
	map <string, string> Dictionary;
	Dictionary["TestKey"] = "TestValue";
}

string RealSubject::Create(string key, string value) {
	Dictionary[key] = value;
}

string RealSubject::Read(string key) {
	Dictionary[key] = value;
}

bool RealSubject::Update(string key, string value) {
	if (dictionary.find(key) != dictionary.end()) {
		dictionary[key] = value;
		return true;
	} else {
		return false;
	}
}

bool RealSubject::Delete(string key) {
	if (dictionary.find(key) != dictionary.end()) {
		dictionary.erase(dictionary.find(key));
		return true;
	}

	return false;
}
