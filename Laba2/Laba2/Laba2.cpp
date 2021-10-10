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
    for (int i = number; i < 1 + number; i++)
    {
        m1.lock();
        ls.push_back(i);
        cout << "Added: " << i << endl;
        m1.unlock();
    }
}

void ListContains(int number)
{
    for (int i = 0; i < 1; i++)
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

    thread t1(AddToList, 10);

    thread t2(ListContains, 10);

    t1.join();
    t2.join();
    system("pause");
    return 0;
}