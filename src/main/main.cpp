#include "../../inc/node.h"
#include "../../inc/analyzer.h"
#include <cstdio>
#include "../../inc/mu_test.h"

UNIT(simple)
Analyzer analyzer(1000);
Node tree(6);
tree.AddLeft(new Node(5));
tree.GetLeft()->AddLeft(new Node(7));
tree.GetLeft()->AddRight(new Node(6));
tree.GetLeft()->GetRight()->AddRight(new Node(6));
tree.AddRight(new Node(1));
tree.GetRight()->AddRight(new Node(6));
tree.GetRight()->GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->AddLeft(new Node(1));

ASSERT_THAT(analyzer.GetResult(&tree) == 3);
END_UNIT

UNIT(empty)
    Node* tree = NULL;
Analyzer analyzer(100);
ASSERT_THAT(analyzer.GetResult(tree) == 0);
END_UNIT

UNIT(list)
Analyzer analyzer(100);
Node tree(1);
tree.AddRight(new Node(2));
tree.GetRight()->AddRight(new Node(3));
tree.GetRight()->GetRight()->AddRight(new Node(4));
tree.GetRight()->GetRight()->GetRight()->AddRight(new Node(5));
tree.GetRight()->GetRight()->GetRight()->GetRight()->AddRight(new Node(5));
ASSERT_THAT(analyzer.GetResult(&tree) == 5);
END_UNIT

UNIT(list1)
Analyzer analyzer(100);
Node tree(1);
tree.AddRight(new Node(2));
tree.GetRight()->AddRight(new Node(3));
tree.GetRight()->GetRight()->AddRight(new Node(4));
tree.GetRight()->GetRight()->GetRight()->AddRight(new Node(5));
tree.GetRight()->GetRight()->GetRight()->GetRight()->AddRight(new Node(6));
ASSERT_THAT(analyzer.GetResult(&tree) == 6);
END_UNIT

UNIT(list2)
Analyzer analyzer(100);
Node tree(1);
tree.AddRight(new Node(1));
tree.GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->GetRight()->GetRight()->AddRight(new Node(1));
ASSERT_THAT(analyzer.GetResult(&tree) == 1);
END_UNIT

UNIT(all_same)
Analyzer analyzer(1000);
Node tree(1);
tree.AddLeft(new Node(1));
tree.GetLeft()->AddLeft(new Node(1));
tree.GetLeft()->AddRight(new Node(1));
tree.GetLeft()->GetRight()->AddRight(new Node(1));
tree.AddRight(new Node(1));
tree.GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->AddRight(new Node(1));
tree.GetRight()->GetRight()->AddLeft(new Node(1));

ASSERT_THAT(analyzer.GetResult(&tree) == 1);
END_UNIT


TEST_SUITE(Tree)
TEST(simple)
    TEST(empty)
    TEST(list)
    TEST(list1)
    TEST(list2)
    TEST(all_same)
END_SUITE
