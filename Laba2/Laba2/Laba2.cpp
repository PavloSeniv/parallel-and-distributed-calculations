//Task1 mutex
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//list<int> listNumber;
//mutex mutex1;
//void AddToList(int numberAdd){
//	mutex1.lock();
//	listNumber.push_back(numberAdd);
//	cout << numberAdd << " Added\n";
//	mutex1.unlock();
//}
//
//void ListContains(int numberAdd){
//	mutex1.lock();
//	auto exist = find(listNumber.begin(), listNumber.end(), numberAdd);
//	if (exist != listNumber.end()) {
//		cout << numberAdd << " True \n";
//	}
//	else
//	{
//		cout << numberAdd << " False \n";
//	}
//	mutex1.unlock();
//}
//
//int main() {
//	auto numberMain = 16;
//	for (int i = 0; i <= 10; i++)
//	{
//		thread t1(AddToList, numberMain);
//		thread t2(ListContains, 19);
//		numberMain++;
//		t1.detach();
//		t2.detach();
//	}
//	Sleep(1000);
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
//
//list<int> listNumber;
//mutex mutex1;
//
//void AddToList(int numberAdd){
//	lock_guard<std::mutex> guard(mutex1);
//	listNumber.push_back(numberAdd);
//	cout << numberAdd << " Added\n";
//}
//
//void ListContains(int numberAdd){
//	lock_guard<std::mutex> guard(mutex1);
//	auto exist = find(listNumber.begin(), listNumber.end(), numberAdd);
//	if (exist != listNumber.end()) {
//		cout << numberAdd << " True \n";
//	}
//	else
//	{
//		cout << numberAdd << " False \n";
//	}
//}
//
//int main() {
//	auto numberMain = 16;
//	for (int i = 0; i <= 10; i++){
//		thread t1(AddToList, numberMain);
//		thread t2(ListContains, 19);
//		numberMain++;
//		t1.detach();
//		t2.detach();
//	}
//	Sleep(1000);
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
//	string firstNamePeople;
//	string lastNamePeople;
//	string addressPeople;
//	int agePeople;
//};
//
//class exchangePerson {
//public:
//	someData someData;
//	mutex Mutex1;
//
//	static void JohnDoe(exchangePerson& people1) {
//		lock_guard<mutex> guard(people1.Mutex1);
//		people1.someData.firstNamePeople = "John";
//		people1.someData.lastNamePeople = "Doe";
//		people1.someData.addressPeople = "Unknown";
//		people1.someData.agePeople = 120;
//	}
//
//	static void JacobSmith(exchangePerson& people2) {
//		lock_guard<mutex> guard(people2.Mutex1);
//		people2.someData.firstNamePeople = "Jacob";
//		people2.someData.lastNamePeople = "Smith";
//		people2.someData.addressPeople = "Known";
//		people2.someData.agePeople = 1;
//	}
//
//	static void Swap(exchangePerson& people1, exchangePerson& people2) {
//		Show(people1, "Person 1 before swap");
//		Show(people2, "Person 2 before swap");
//		if (addressof(people1) != addressof(people2))
//		{
//			lock(people1.Mutex1, people2.Mutex1);
//			lock_guard<mutex> lock1(people1.Mutex1, adopt_lock);
//			lock_guard<mutex> lock2(people2.Mutex1, adopt_lock);
//
//			exchangePerson newPerson;
//
//			newPerson.someData.firstNamePeople = people1.someData.firstNamePeople;
//			newPerson.someData.lastNamePeople = people1.someData.lastNamePeople;
//			newPerson.someData.addressPeople = people1.someData.addressPeople;
//			newPerson.someData.agePeople = people1.someData.agePeople;
//
//			people1.someData.firstNamePeople = people2.someData.firstNamePeople;
//			people1.someData.lastNamePeople = people2.someData.lastNamePeople;
//			people1.someData.addressPeople = people2.someData.addressPeople;
//			people1.someData.agePeople = people2.someData.agePeople;
//
//			people2.someData.firstNamePeople = newPerson.someData.firstNamePeople;
//			people2.someData.lastNamePeople = newPerson.someData.lastNamePeople;
//			people2.someData.addressPeople = newPerson.someData.addressPeople;
//			people2.someData.agePeople = newPerson.someData.agePeople;
//			Show(people1, "Person 1 after swap");
//			Show(people2, "Person 2 after swap");
//		}
//	}
//
//	static void Show(exchangePerson& person, string text) {
//		cout << text << " -> firstName - " << person.someData.firstNamePeople << ", lastName - " << person.someData.lastNamePeople << ", age - " << person.someData.agePeople << ", address - " << person.someData.addressPeople << "\n";
//	}
//};
//
//int main() {
//	exchangePerson people1;
//	exchangePerson people2;
//
//	thread t1(exchangePerson::JohnDoe, ref(people1));
//	t1.detach();
//	thread t2(exchangePerson::JacobSmith, ref(people1));
//	t2.detach();
//
//	thread t3(exchangePerson::JacobSmith, ref(people2));
//	t3.detach();
//	thread t4(exchangePerson::JohnDoe, ref(people2));
//	t4.detach();
//
//	thread t5(exchangePerson::Swap, ref(people1), ref(people2));
//	t5.join();
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
	string firstNamePeople;
	string lastNamePeople;
	string addressPeople;
	int agePeople;
};

class exchangePerson {
public:
	someData someData;
	mutex Mutex1;


	static void JohnDoe(exchangePerson& people1) {
		lock_guard<mutex> guard(people1.Mutex1);
		people1.someData.firstNamePeople = "John";
		people1.someData.lastNamePeople = "Doe";
		people1.someData.addressPeople = "Unknown";
		people1.someData.agePeople = 120;
	}

	static void JacobSmith(exchangePerson& people2) {
		lock_guard<mutex> guard(people2.Mutex1);
		people2.someData.firstNamePeople = "Jacob";
		people2.someData.lastNamePeople = "Smith";
		people2.someData.addressPeople = "Known";
		people2.someData.agePeople = 1;
	}

	static void Swap(exchangePerson& people1, exchangePerson& people2) {
		Show(people1, "Person 1 before swap");
		Show(people2, "Person 2 before swap");
		if (addressof(people1) != addressof(people2))
		{
			unique_lock<mutex> lock1(people1.Mutex1, defer_lock);
			unique_lock<mutex> lock2(people2.Mutex1, defer_lock);
			lock(lock1, lock2);

			exchangePerson newPerson;

			newPerson.someData.firstNamePeople = people1.someData.firstNamePeople;
			newPerson.someData.lastNamePeople = people1.someData.lastNamePeople;
			newPerson.someData.addressPeople = people1.someData.addressPeople;
			newPerson.someData.agePeople = people1.someData.agePeople;

			people1.someData.firstNamePeople = people2.someData.firstNamePeople;
			people1.someData.lastNamePeople = people2.someData.lastNamePeople;
			people1.someData.addressPeople = people2.someData.addressPeople;
			people1.someData.agePeople = people2.someData.agePeople;

			people2.someData.firstNamePeople = newPerson.someData.firstNamePeople;
			people2.someData.lastNamePeople = newPerson.someData.lastNamePeople;
			people2.someData.addressPeople = newPerson.someData.addressPeople;
			people2.someData.agePeople = newPerson.someData.agePeople;
			Show(people1, "Person 1 after swap");
			Show(people2, "Person 2 after swap");
		}
	}

	static void Show(exchangePerson& person, string text) {
		cout << text << " -> firstName - " << person.someData.firstNamePeople << ", lastName - " << person.someData.lastNamePeople << ", age - " << person.someData.agePeople << ", address - " << person.someData.addressPeople << "\n";
	}
};

int main() {
	exchangePerson people1;
	exchangePerson people2;

	thread t1(exchangePerson::JohnDoe, ref(people1));
	t1.detach();
	thread t2(exchangePerson::JacobSmith, ref(people1));
	t2.detach();

	thread t3(exchangePerson::JacobSmith, ref(people2));
	t3.detach();
	thread t4(exchangePerson::JohnDoe, ref(people2));
	t4.detach();

	thread t5(exchangePerson::Swap, ref(people1), ref(people2));
	t5.join();

	system("pause");
	return 0;
}
