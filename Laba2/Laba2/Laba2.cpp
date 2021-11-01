//Task1 mutex
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//list<int> l;
//mutex m1;
//
//void AddToList(int number){
//
//	m1.lock();
//	l.push_back(number);
//	cout << number << " - pushed!\n";
//	m1.unlock();
//}
//
//void ListContains(int number){
//
//	m1.lock();
//	auto exist = find(l.begin(), l.end(), number);
//
//	if (exist != l.end()) {
//		cout << number << " - exist\n";
//	}
//	else
//	{
//		cout << number << " - not exist\n";
//	}
//
//	m1.unlock();
//}
//
//int main() {
//
//	auto number = 16;
//	for (int i = 0; i <= 10; i++)
//	{
//		thread t1(AddToList, number);
//		thread t2(ListContains, 19);
//		number++;
//		t1.join();
//		t2.join();
//	}
//
//	system("pause");
//	return 0;
//}

//Task1 lock_guard
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//list<int> l;
//mutex m1;
//
//void AddToList(int number){
//
//	lock_guard<std::mutex> guard(m1);
//	l.push_back(number);
//	cout << number << " - pushed!\n";
//}
//
//void ListContains(int number){
//
//	lock_guard<std::mutex> guard(m1);
//	auto exist = find(l.begin(), l.end(), number);
//	if (exist != l.end()) {
//		cout << number << " - exist\n";
//	}
//	else
//	{
//		cout << number << " - not exist\n";
//	}
//}
//
//int main() {
//
//	auto number = 16;
//	for (int i = 0; i <= 10; i++)
//	{
//		thread t1(AddToList, number);
//		thread t2(ListContains, 19);
//		number++;
//		t1.join();
//		t2.join();
//	}
//	system("pause");
//	return 0;
//}
 
//Task2
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//
//class someData {
//public:
//	string firstName;
//	string lastName;
//	string address;
//	int age;
//};
//
//class exchangePerson {
//
//public:
//	someData data;
//	mutex myMutex;
//
//	static void JohnDoe(exchangePerson& person) {
//
//		lock_guard<mutex> guard(person.myMutex);
//		person.data.firstName = "John";
//		person.data.lastName = "Doe";
//		person.data.address = "Unknown";
//		person.data.age = 120;
//	}
//
//	static void JacobSmith(exchangePerson& person) {
//
//		lock_guard<mutex> guard(person.myMutex);
//		person.data.firstName = "Jacob";
//		person.data.lastName = "Smith";
//		person.data.address = "Known";
//		person.data.age = 1;
//	}
//
//	static void Swap(exchangePerson& p1, exchangePerson& p2) {
//
//		Show(p1, "Person 1 before swap");
//		Show(p2, "Person 2 before swap");
//
//		if (!AreEqual(p1, p2)){
//
//			lock(p1.myMutex, p2.myMutex);
//			lock_guard<mutex> lock1(p1.myMutex, adopt_lock);
//			lock_guard<mutex> lock2(p2.myMutex, adopt_lock);
//
//			exchangePerson newPerson;
//
//			newPerson.data.firstName = p1.data.firstName;
//			newPerson.data.lastName = p1.data.lastName;
//			newPerson.data.address = p1.data.address;
//			newPerson.data.age = p1.data.age;
//
//			p1.data.firstName = p2.data.firstName;
//			p1.data.lastName = p2.data.lastName;
//			p1.data.address = p2.data.address;
//			p1.data.age = p2.data.age;
//
//			p2.data.firstName = newPerson.data.firstName;
//			p2.data.lastName = newPerson.data.lastName;
//			p2.data.address = newPerson.data.address;
//			p2.data.age = newPerson.data.age;
//
//			Show(p1, "Person 1 after swap");
//			Show(p2, "Person 2 after swap");
//		}
//	}
//
//	static void Show(exchangePerson& person, string text) {
//		cout << text << " -> firstName - " << person.data.firstName << ", lastName - " << person.data.lastName << ", age - " << person.data.age << ", address - " << person.data.address << "\n";
//	}
//
//	static bool AreEqual(const exchangePerson& a, const exchangePerson& b){
//		return addressof(a) == addressof(b);
//	}
//};
//
//
//void JohnDoe(exchangePerson& person){
//	person.JohnDoe(person);
//	person.Show(person, "Person 1");
//}
//
//void JacobSmith(exchangePerson& person){
//	person.JacobSmith(person);
//	person.Show(person, "Person 2");
//}
//
//void Swap(exchangePerson& person1, exchangePerson& person2){
//	person1.Swap(person1, person2);
//	person2.Swap(person1, person2);
//}
//
//int main() {
//	exchangePerson person1;
//	exchangePerson person2;
//
//	thread t1(JohnDoe, ref(person1));
//	t1.join();
//	thread t2(JacobSmith, ref(person2));
//	t2.join();
//
//	thread t3(Swap, ref(person1), ref(person2));
//	t3.join();
//
//	system("pause");
//	return 0;
//}

//Task3
#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <list>
#include <algorithm>

using namespace std;

class someData {

public:
	string firstName;
	string lastName;
	string address;
	int age;
};

class exchangePerson {

public:
	someData data;
	mutex myMutex;

	static void JohnDoe(exchangePerson& person) {
		lock_guard<mutex> guard(person.myMutex);
		person.data.firstName = "John";
		person.data.lastName = "Doe";
		person.data.address = "Unknown";
		person.data.age = 120;
	}

	static void JacobSmith(exchangePerson& person) {
		lock_guard<mutex> guard(person.myMutex);
		person.data.firstName = "Jacob";
		person.data.lastName = "Smith";
		person.data.address = "Known";
		person.data.age = 1;
	}

	static void Swap(exchangePerson& p1, exchangePerson& p2) {
		Show(p1, "Person 1 before swap");
		Show(p2, "Person 2 before swap");

		if (!AreEqual(p1, p2)){

			unique_lock<mutex> lock1(p1.myMutex, defer_lock);
			unique_lock<mutex> lock2(p2.myMutex, defer_lock);
			lock(lock1, lock2);

			exchangePerson newPerson;

			newPerson.data.firstName = p1.data.firstName;
			newPerson.data.lastName = p1.data.lastName;
			newPerson.data.address = p1.data.address;
			newPerson.data.age = p1.data.age;

			p1.data.firstName = p2.data.firstName;
			p1.data.lastName = p2.data.lastName;
			p1.data.address = p2.data.address;
			p1.data.age = p2.data.age;

			p2.data.firstName = newPerson.data.firstName;
			p2.data.lastName = newPerson.data.lastName;
			p2.data.address = newPerson.data.address;
			p2.data.age = newPerson.data.age;

			Show(p1, "Person 1 after swap");
			Show(p2, "Person 2 after swap");
		}
	}

	static void Show(exchangePerson& person, string text) {
		cout << text << " -> firstName - " << person.data.firstName << ", lastName - " << person.data.lastName << ", age - " << person.data.age << ", address - " << person.data.address << "\n";
	}

	static bool AreEqual(const exchangePerson& a, const exchangePerson& b){
		return addressof(a) == addressof(b);
	}
};


void JohnDoe(exchangePerson& person){
	person.JohnDoe(person);
	person.Show(person, "Person 1");
}

void JacobSmith(exchangePerson& person){
	person.JacobSmith(person);
	person.Show(person, "Person 2");
}

void Swap(exchangePerson& person1, exchangePerson& person2){
	person1.Swap(person1, person2);
	person2.Swap(person1, person2);
}

int main() {
	exchangePerson person1;
	exchangePerson person2;

	thread t1(JohnDoe, ref(person1));
	t1.join();
	thread t2(JacobSmith, ref(person2));
	t2.join();

	thread t3(Swap, ref(person1), ref(person2));
	t3.join();

	system("pause");
	return 0;
}

