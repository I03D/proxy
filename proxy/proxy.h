#pragma once
#include "proxy.h"
#include "Subject.h"
#include <iostream>

using namespace std;

class proxy : Subject
{
private:
	Subject subject;
	string role;
public:
	int Proxy(Subject subject, string role) {
		this->subject = subject;
		this->role = role;
	}

	void Create(string key, string value) {
		if (role == "Owner")
			this->subject->Create(key, value);
		else
			throw new UnauthorizedAccessException("Create: Access denied.");
	}

	string Read(string key) {
		return this->subject->Read(key);
	}

	bool Update(string key, string value) {
		if (role != "User")
			return this->subject->Update(key, value);
		else
			throw new UnauthorizedAccessException("Update: Access denied.");
	}

	bool Delete(string key) {
		if (role == "Administrator" || role == "Owner")
			return this->subject->Delete(key);
		else
			throw new UnauthorizedAccessException("Create: Access denied.");
	}

	static void Main(string[] args) {
		Subject subject = new RealSubject();

		cout << "Owner work: ";
		TryAccess(new Proxy(subject, "Owner"), "John");

		cout << "Administrator work: ";
		TryAccess(new Proxy(subject, "Manager"), "Lola");

		cout << "Manager work: ";
		TryAccess(new Proxy(subject, "User"), "Gigi");
	}
	
	static void TryAccess(Subject proxy, string name) {
		try {
			proxy.Create(name, "TestValue");
			cout << "Create - OK!";
		}
		catch (Exception ex) {
			cout << ex.Message;
		}

		try {
			proxy.Update(name, "NewTestValue");
			cout << "Update - OK!";
		}
		catch (Exception ex) {
			cout << ex.Message;
		}

		try {
			proxy.Delete(name);
			cout << "Delete - OK!"
		}
		catch (Exception ex) {
			cout << ex.Message;
		}

		Console.WriteLine(new string('-', 50));
	}
};
