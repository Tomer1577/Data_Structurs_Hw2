#ifndef CLASSLIST
#define CLASSLIST

#include "Array.h"
#include <memory>

#define NOCLASS -1
#define INITIAL_CLASS_SIZE 1


class ClassList
{
    private:
    std::shared_ptr<Array<int>> classes;
    int numOfClasses;

    void GrowArray();

    public:
    ClassList();
    ClassList& operator=(const ClassList& other) = delete;
    ~ClassList() = default;
    void AddClass();
    int& operator[](int classID);
    int GetClassnum();




};

#endif //ClassList