#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type, // or value type, if we want map instead of set
less<>, // or less_equal, if we want multi-version; also greater or something
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// usage
ordered_set X;
X.insert(1);
X.insert(2);
cout << *X.find_by_order(1) << endl; // iterator to k-th by value element, starting on zero
cout << X.order_of_key(-5) << endl; // a number of elements strictly less than given
