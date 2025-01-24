#ifndef PARALLEL_VECTORS_H
#define PARALLEL_VECTORS_H

#include <vector>
#include <string>

template <typename T1, typename T2>
class ParallelVectors
{
private:
    std::vector<T1> first;
    std::vector<T2> second;

public:
    void addPair(const T1& f, const T2& s)
    {
        first.push_back(f);
        second.push_back(s);
    }

    size_t size() const
    {
        return first.size(); // same size as second
    }

    T1 getFirstAt(size_t index) const
    {
        return first.at(index);
    }

    T2 getSecondAt(size_t index) const
    {
        return second.at(index);
    }
};

#endif // PARALLEL_VECTORS_H