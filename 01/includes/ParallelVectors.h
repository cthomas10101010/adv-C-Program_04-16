#ifndef PARALLEL_VECTORS_H
#define PARALLEL_VECTORS_H

#include <vector>
#include <string>

/**
 * @brief A class template that uses two parallel vectors to hold pairs of data.
 */
template <typename T1, typename T2>
class ParallelVectors {
private:
    std::vector<T1> first;
    std::vector<T2> second;

public:
    /**
     * @brief Adds a pair of elements to the parallel vectors.
     * @param firstElement The element to add to the first vector.
     * @param secondElement The element to add to the second vector.
     */
    void addPair(const T1& firstElement, const T2& secondElement) {
        first.push_back(firstElement);
        second.push_back(secondElement);
    }

    /**
     * @brief Returns the number of pairs stored.
     * @return The size of the vectors.
     */
    size_t size() const {
        return first.size();
    }

    /**
     * @brief Gets the first element at the given index.
     * @param index The index in the vector.
     * @return The element at the given index in the first vector.
     */
    T1 getFirstAt(size_t index) const {
        return first.at(index);
    }

    /**
     * @brief Gets the second element at the given index.
     * @param index The index in the vector.
     * @return The element at the given index in the second vector.
     */
    T2 getSecondAt(size_t index) const {
        return second.at(index);
    }
};

#endif // PARALLEL_VECTORS_H
