//Task1
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//
//using namespace std;
//
//
//void thread_for1() {
//	cout << 1 << endl;
//}
//void thread_for2() {
//	cout << 2 << endl;
//}
//
//int main()
//{
//	thread t1(thread_for1);
//	thread t2(thread_for2);
//
//	Sleep(1000);
//
//	return 0;
//}

//Task 2
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <Windows.h>
//
//using namespace std;
//
//
//void thread_for1() {
//	cout << 1 << endl;
//}
//void thread_for2() {
//	cout << 2 << endl;
//}
//
//int main()
//{
//	thread t1(thread_for1);
//	thread t2(thread_for2);
//
//	Sleep(1000);
//
//	t1.detach();
//	t2.detach();
//
//	system("pause");
//	return 0;
//}

//Task 3
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <list>
//#include <algorithm>
//
//
//using namespace std;
//
//list<int> ls;
//
//
//void AddToList(int number)
//{
//    for (int i = number; i < 10 + number; i++)
//    {
//        ls.push_back(i);
//        cout << "Added: " << i << endl;
//    }
//}
//
//void ListContains(int number)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        bool found = (find(ls.begin(), ls.end(), number) != ls.end());
//
//        if (found)
//        {
//            cout << "True " << endl;
//        }
//        else {
//            cout << "False " << endl;
//        }
//    }
//}
//
//int main() {
//
//    thread t1(AddToList, 12);
//
//    thread t2(ListContains, 18);
//
//    t1.join();
//    t2.join();
//
//    system("pause");
//    return 0;
//}

//Task 4
#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <algorithm>


using namespace std;

mutex m1;

list<int> ls;


void AddToList(int number)
{
    for (int i = number; i < 10 + number; i++)
    {
        m1.lock();
        ls.push_back(i);
        cout << "Added: " << i << endl;
        m1.unlock();
    }
}

void ListContains(int number)
{
    for (int i = 0; i < 10; i++)
    {
        m1.lock();
        bool found = (find(ls.begin(), ls.end(), number) != ls.end());

        if (found)
        {
            cout << "True " << endl;
        }
        else {
            cout << "False " << endl;
        }
        m1.unlock();
    }
}

int main() {

    thread t1(AddToList, 12);

    thread t2(ListContains, 18);

    t1.join();
    t2.join();
    system("pause");
    return 0;
}
