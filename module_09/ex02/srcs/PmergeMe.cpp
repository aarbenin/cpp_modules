#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {
    (void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    if (n == 0)
        return result;
    result.push_back(0);
    if (n == 1)
        return result;
    result.push_back(1);
    size_t prevprev = 0;
    size_t prev     = 1;
    while (true) {
        size_t next = prev + 2 * prevprev; // j(n) = j(n-1) + 2*j(n-2)
        if (next >= n)
            break;
        if (next != prev) {
            result.push_back(next);
        }
        prevprev = prev;
        prev     = next;
    }

    for (size_t i = 0; i < n; i++) {
        if (std::find(result.begin(), result.end(), i) == result.end()) {
            result.push_back(i);
        }
    }
    return result;
}

// VECTOR
// ============================================================================

void PmergeMe::createPairsVector(const std::vector<int>& arr,
                                 std::vector<int>&       small,
                                 std::vector<int>&       big) {
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            small.push_back(arr[i]);
            big.push_back(arr[i + 1]);
        } else {
            small.push_back(arr[i + 1]);
            big.push_back(arr[i]);
        }
    }
    if (arr.size() % 2 == 1) {
        small.push_back(arr.back());
    }
}

void PmergeMe::fordJohnsonRecVector(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    std::vector<int> small;
    std::vector<int> big;
    createPairsVector(arr, small, big);

    fordJohnsonRecVector(big);

    insertJacobsthalVector(small, big);

    arr = big;
}

void PmergeMe::insertJacobsthalVector(const std::vector<int>& small,
                                      std::vector<int>&       big) {
    if (small.empty())
        return;

    std::vector<size_t> jac = generateJacobsthalIndices(small.size());

    for (size_t idx : jac) {
        if (idx >= small.size())
            continue;
        int                        val = small[idx];
        std::vector<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), val);
        big.insert(pos, val);
    }
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    fordJohnsonRecVector(arr);
}

// DEQUE
// ============================================================================

void PmergeMe::createPairsDeque(const std::deque<int>& arr,
                                std::deque<int>& small, std::deque<int>& big) {
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            small.push_back(arr[i]);
            big.push_back(arr[i + 1]);
        } else {
            small.push_back(arr[i + 1]);
            big.push_back(arr[i]);
        }
    }
    if (arr.size() % 2 == 1) {
        small.push_back(arr.back());
    }
}

void PmergeMe::fordJohnsonRecDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    std::deque<int> small;
    std::deque<int> big;
    createPairsDeque(arr, small, big);

    fordJohnsonRecDeque(big);

    insertJacobsthalDeque(small, big);

    arr = big;
}

void PmergeMe::insertJacobsthalDeque(const std::deque<int>& small,
                                     std::deque<int>&       big) {
    if (small.empty())
        return;

    std::vector<size_t> jac = generateJacobsthalIndices(small.size());

    for (size_t idx : jac) {
        if (idx >= small.size())
            continue;
        int                       val = small[idx];
        std::deque<int>::iterator it  = big.begin();
        for (; it != big.end(); ++it) {
            if (*it >= val)
                break;
        }
        big.insert(it, val);
    }
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    fordJohnsonRecDeque(arr);
}
