#include <iostream>

#include "Student.hpp"

void setStudent(Student & Stu, int numQuiz);

int main(void)
{
    int numStu = 3;
    int numQuiz = 5;

    Student StuArray[numStu] = { Student{numQuiz}, Student{numQuiz}, Student{numQuiz} };
    // We should have 3 Student object now, each with 5 scores capacity.
    
    std::cout << "1. Let's check default Student name...\n";
    for (int i = 0; i < numStu; i++)
    {
        std::cout << StuArray[i] << '\n'; // Ouptut Student element's name.
    }

    std::cout << "2. Let's set each Student object...\n";
    for (int i = 0; i < numStu; i++)
    {
        setStudent(StuArray[i], numQuiz);
    }

    std::cout << "3. Let's check setted Student information...\n";
    for (int i = 0; i < numStu; i++)
    {
        std::cout<<StuArray[i].Name() <<", with average score : " <<StuArray[i].Average() << "\n";
    }

    return 0;
}

void setStudent(Student & Stu, int numQuiz)
{
     std::cout << "Please enter student's name : ";
     getline(std::cin, Stu);

     std::cout << "Please enter " << numQuiz << " quiz scores : ";
     for(int i = 0; i < numQuiz; i++)
     {
         std::cin >> Stu[i]; 
     }

     // Clear input buffer 
     while (std::cin.get() != '\n')
         continue;
}
