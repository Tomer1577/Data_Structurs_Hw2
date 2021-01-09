#ifndef CLASSLIST
#define CLASSLIST

#include "Array.h"
#include <memory>

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
    void WatchClass(int classID, int time);
    int TimeWatched(int classID);
    int GetClassnum();




};

#endif //ClassList