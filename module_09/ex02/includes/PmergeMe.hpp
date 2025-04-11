#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void fordJohnsonSortVector(std::vector<int>& arr);
    static void fordJohnsonSortDeque(std::deque<int>& arr);

private:
    static void createPairsVector(const std::vector<int>& arr,
                                  std::vector<int>&       small,
                                  std::vector<int>&       big);

    static void insertJacobsthalVector(const std::vector<int>& small,
                                       std::vector<int>&       big);

    static void fordJohnsonRecVector(std::vector<int>& arr);

    static void createPairsDeque(const std::deque<int>& arr,
                                 std::deque<int>& small, std::deque<int>& big);

    static void insertJacobsthalDeque(const std::deque<int>& small,
                                      std::deque<int>&       big);

    static void fordJohnsonRecDeque(std::deque<int>& arr);

    static std::vector<size_t> generateJacobsthalIndices(size_t n);
};

#endif
