#include <ext/pb_ds/detail/standard_policies.hpp>

typedef tree<
int,
null_type, // или тип значения, если не set, а map хотим
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// usage 
ordered_set X;
X.insert(1); // итератор на k-й по величине элемент (отсчет с нуля)
X.insert(2);
cout << *X.find_by_order(1) << endl; // количество элементов, строго меньших данного
cout << X.order_of_key(-5) << endl;
