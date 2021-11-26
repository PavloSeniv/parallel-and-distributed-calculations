//Task1
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <queue>
//#include <Windows.h>
//
//using namespace std;
//
//bool isEnd = false;
//mutex mut;
//queue<int> q;
//
//int primeNumber(unsigned long a, unsigned long i)
//{
//	return i * i <= a ? (a % i) && primeNumber(a, i + 1) : 1;
//}
//
//void dataPreparation() {
//	int count = 0;
//	cout << "Enter the number of numbers: ";
//	cin >> count;
//	for (int i = 0; i < count; i++)
//	{
//		int value = 0;
//		cout << "Enter number: ";
//		cin >> value;
//		q.push(value);
//	}
//	isEnd = true;
//}
//
//void dataProcessing() {
//	unique_lock<std::mutex> lk(mut);
//	while (!isEnd) {
//		lk.unlock();
//		this_thread::sleep_for(chrono::milliseconds(100));
//		lk.lock();
//	}
//	cout << "Processing" << endl;
//	while (!q.empty()) {
//		int v = q.front();
//		q.pop();
//		auto isPrime = primeNumber((long)v, (long)2);
//		cout << "Number: " << v << " is prime =  " << (isPrime == 1 ? "True" : "False") << endl;
//	}
//}
//
//int main()
//{
//	thread DataPreparation(dataPreparation);
//	thread DataProcessing(dataProcessing);
//	DataPreparation.detach();
//	DataProcessing.join();
//}

////Task2
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <queue>
//#include <Windows.h>
//#include <condition_variable>
//
//using namespace std;
//
//condition_variable dataCondition;
//mutex mut;
//int i = 0;
//
//void Awake() {
//	this_thread::sleep_for(chrono::milliseconds(100));
//	cout << "Informing" << endl;
//	dataCondition.notify_all();
//	this_thread::sleep_for(chrono::milliseconds(100));
//	i = 1;
//	cout << "Updated i=1. Informing" << endl;
//	dataCondition.notify_all();
//}
//
//void Waits() {
//	unique_lock<mutex> lk(mut);
//	cout << "Go to standby" << endl;
//	dataCondition.wait(lk, [] {return i == 1; });
//	cout << "The waiting state is over" << endl;
//}
//
//int main() {
//	thread waits1(Waits);
//	thread waits2(Waits);
//	thread waits3(Waits);
//	thread awakeness(Awake);
//	waits1.detach();
//	waits2.detach();
//	waits3.detach();
//	awakeness.join();
//	Sleep(1000);
//}

////Task3
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <queue>
//#include <Windows.h>
//#include <condition_variable>
//
//using namespace std;
//condition_variable dataCondition;
//mutex mut;
//int i = 0;
//
//void Notify() {
//	this_thread::sleep_for(chrono::milliseconds(200));
//	cout << "Informing" << endl;
//	dataCondition.notify_one();
//	i = 1;
//	cout << "Updated i=1. Informing" << endl;
//	dataCondition.notify_one();
//}
//
//void Waits(int n) {
//	unique_lock<mutex> lk(mut);
//	cout << "Go to standby from the stream: " << n << endl;
//	dataCondition.wait(lk, [] {return i == 1; });
//	cout << "Message from the thread: " << n << endl;
//}
//
//int main() {
//	thread waits1(Waits, 1);
//	thread waits2(Waits, 2);
//	thread waits3(Waits, 3);
//	thread awakeness(Notify);
//	waits1.detach();
//	waits2.detach();
//	waits3.detach();
//	awakeness.join();
//	Sleep(1000);
//}

//Task4
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <Windows.h>

using namespace std;

bool isEnd = false;
mutex mut;
condition_variable dataCondition;
queue<int> q;

int primeNumber(unsigned long a, unsigned long i)
{
	return i * i <= a ? (a % i) && primeNumber(a, i + 1) : 1;
}

void dataPreparation() {
	cout << "False informing" << endl;
	dataCondition.notify_all();
	int count = 0;
	cout << "Enter the number of numbers: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int value = 0;
		cout << "Enter number: ";
		cin >> value;
		q.push(value);
	}
	cout << "Correct notification" << endl;
	dataCondition.notify_all();
}

void dataProcessing() {
	unique_lock<std::mutex> lk(mut);
	cout << "I started waiting" << endl;
	dataCondition.wait(lk, [] {return !q.empty(); });
	cout << "Processing started" << endl;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		auto isPrime = primeNumber((long)v, (long)2);
		cout << "Number: " << v << " is prime =  " << (isPrime == 1 ? "True" : "False") << endl;
	}

}

int main()
{
	thread DataPreparation(dataPreparation);
	thread DataProcessing(dataProcessing);
	DataPreparation.detach();

	DataProcessing.join();
}
