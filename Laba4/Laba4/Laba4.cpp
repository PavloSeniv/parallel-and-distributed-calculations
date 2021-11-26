////Task1
//#include <iostream>
//#include <future>
//#include <chrono>
//
//using namespace std;
//
//int getPrime(int n);
//int root_number(int n);
//
//int main()
//{
//	int number = 1;
//	cout << "Enter the number of prime numbers: ";
//	cin >> number;
//	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
//	future<int> result = async(launch::async, getPrime, number);
//	cout << "Calculate root of " << number <<". Next enter 1" << endl;
//	int choice = 0;
//	cin >> choice;
//	if (choice == 1)
//	{
//		cout << "Square of " << number << ": " << root_number(number) << endl;
//	}
//	int simple = result.get();
//	cout << "Prime number is: " << simple << endl;
//	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//	std::cout << "The time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
//	std::cout << "The time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;
//	system("pause");
//}
//
//int root_number(int n) {
//	return n * n;
//}
//
//int getPrime(int n) {
//	int count = 0;
//	int max_limit = 100;
//	if (max_limit < n)
//	{
//		max_limit = n;
//	}
//	int i = 1;
//	while (count != n)
//	{
//		int kol = 0;
//		for (int j = 1; j <= i; j++)
//			if (i % j == 0) kol++;
//		if (kol == 1 || kol == 2) {
//			count++;
//		}
//		if (count == n)
//		{
//			return i;
//		}
//		i++;
//	}
//	return -1;
//}


//Task2
//#include <iostream>
//#include <future>
//#include <chrono>
//#include <deque>
//#include <queue>
//
//using namespace std;
//
//int getPrime(int n);
//int root_number(int n);
//void task1();
//void task2();
//bool stop = false;
//void dataProcessing();
//
//queue<packaged_task<int(int)>> qTask;
//queue<int> qNumber;
//
//int main()
//{
//	task2();
//	system("pause");
//}
//
//void task2() {
//	thread processing(dataProcessing);
//	while (!stop)
//	{
//		int number = 1;
//		cout << "Enter the number of prime numbers: ";
//		cin >> number;
//		if (number == -1)
//			stop = true;
//		packaged_task<int(int)> task(getPrime);
//		qTask.push(move(task));
//		qNumber.push(number);
//	}
//	processing.join();
//}
//
//void dataProcessing() {
//	while (!stop)
//	{
//		if (!qTask.empty())
//		{
//			packaged_task<int(int)> task = move(qTask.front());
//			qTask.pop();
//			int N = qNumber.front();
//			qNumber.pop();
//			task(N);
//		}
//	}
//}
//int getPrime(int n) {
//	int count = 0;
//	int max_limit = 100;
//	if (max_limit < n)
//	{
//		max_limit = n;
//	}
//	int i = 1;
//	while (count != n)
//	{
//		int kol = 0;
//		for (int j = 1; j <= i; j++)
//			if (i % j == 0) kol++;
//		if (kol == 1 || kol == 2) {
//			count++;
//		}
//		if (count == n)
//		{
//
//			cout << "---Current number: " << n << " prime is " << i << endl;
//			return i;
//		}
//		i++;
//	}
//	return -1;
//}

//Task3
#include <iostream>
#include <future>
#include <chrono>
#include <deque>
#include <queue>

using namespace std;
int getPrime(int n);
void task3();
void currentOne(int N, promise<int> primePromise, promise<int> primePromise10, promise<bool> isReadyPromise) {
	future<int> result = async(launch::async, getPrime, N);
	int res = result.get();
	move(primePromise).set_value(res);
	move(isReadyPromise).set_value(true);
	move(primePromise10).set_value(res * 10);

}

void currentTwo(future<bool> isReadyPromise, shared_future<int> primePromise) {
	auto res = isReadyPromise.get();
	if (res)
	{
		this_thread::sleep_for(2000ms);
		auto n = primePromise.get();
		cout << "Mul is " << n * n << endl;
	}
}

int main()
{
	task3();
	system("pause");
}

void task3() {
	promise<int> ntePrime;
	promise<int> nPrimex10;
	promise<bool> isReady;
	shared_future<int> primeFuture = ntePrime.get_future();
	auto nPrime10Future = nPrimex10.get_future();
	auto isReadyFuture = isReady.get_future();
	int Nte = 1;
	cout << "Enter the number of prime numbers: ";
	cin >> Nte;
	thread t1(currentOne, Nte, move(ntePrime), move(nPrimex10), move(isReady));
	thread t2(currentTwo, move(isReadyFuture), primeFuture);
	t1.detach();
	t2.detach();
	int nValue = primeFuture.get();
	cout << "Prime number is " << nValue << endl;
	int n10Value = nPrime10Future.get();
	cout << "Number mul 10 is " << n10Value << endl;


	system("pause");

}
int getPrime(int n) {
	int count = 0;
	int limit = 100;
	if (limit < n)
	{
		limit = n;
	}
	int i = 1;
	while (count != n)
	{
		int kol = 0;
		for (int j = 1; j <= i; j++)
			if (i % j == 0) kol++;
		if (kol == 1 || kol == 2) {
			count++;
		}
		if (count == n)
		{
			return i;
		}
		i++;
	}
	return -1;
}

