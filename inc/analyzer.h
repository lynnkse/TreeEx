#ifndef ANALYZER
#define ANALYZER

#include <vector>

class Analyzer
{
public:
    explicit Analyzer(size_t _n);
    size_t GetResult(const Node * const _tree);
private:
    const size_t N;
    std::vector<int> vec;
};

#endif //ANALYZER
