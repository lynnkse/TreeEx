#include <node.h>
#include <analyzer.h>

Analyzer::Analyzer(size_t _n):
    N(_n),
    vec(_n, 0)
{}


 size_t Analyzer::GetResult(const Node * const  _tree) 
{
    if(!_tree)
    {
	return 0;
    }

    size_t left = 0;
    size_t right = 0;
    int currData = _tree->GetData();

    size_t res = (!vec[currData]);
    ++vec[currData];

    const Node * const rNode = _tree->GetRight();
    const Node * const lNode = _tree->GetLeft();
    
    if(lNode)
    {
	left = GetResult(lNode);
    }
    if(rNode)
    {
	right = GetResult(rNode);
    }

    --vec[currData];

    return left > right ? left + res : right + res;
}
