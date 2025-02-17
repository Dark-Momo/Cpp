#include "MI.hpp"

const int SIZE = 3;

int main()
{
    std::cout << "\n----------------------------------------------------------------\n";
    // Running code shows here, we don't have any output.
    // So initialize class pointer array doesn't trigger constructor.
    Worker * WorkerObjList[SIZE];

    std::cout << "\n----------------------------------------------------------------\n";
    std::cout << "================================ WorkerObjList[0] = new Waiter;\n";
    WorkerObjList[0] = new Waiter;
    std::cout << "================================ WorkerObjList[0]->Set();\n";
    WorkerObjList[0]->Set();
    std::cout << "================================ WorkerObjList[0]->Show();\n";
    WorkerObjList[0]->Show();

    std::cout << "\n----------------------------------------------------------------\n";
    std::cout << "================================ WorkerObjList[1] = new Singer;\n";
    WorkerObjList[1] = new Singer;
    std::cout << "================================ WorkerObjList[1]->Set();\n";
    WorkerObjList[1]->Set();
    std::cout << "================================ WorkerObjList[1]->Show();\n";
    WorkerObjList[1]->Show();

    std::cout << "\n----------------------------------------------------------------\n";
    std::cout << "================================ WorkerObjList[2] = new SingerWaiter;\n";
    WorkerObjList[2] = new SingerWaiter;
    std::cout << "================================ WorkerObjList[2]->Set();\n";
    WorkerObjList[2]->Set();
    std::cout << "================================ WorkerObjList[2]->Show();\n";
    WorkerObjList[2]->Show();

    std::cout << "\n----------------------------------------------------------------\n";
    std::cout << "================================ Will delete all objs\n";
    for (int i = 0; i < SIZE; i++)
        delete WorkerObjList[i];
    // Will call Worker::~Worker() 3 times.

    return 0;
}
