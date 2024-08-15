// Theme: Treap (Tree + Heap)
// Supports both explicit and implicit keys (not simultaniously ofc)
// Core operations are all O(log n) average

mt19937 rng(378);

struct Node {
    int x, y, size; // "x" is key or payload, "y" is priority
    Node* left, * right;

    Node(int val): x(val), y(rng() % 1'000'000'000), size(1), left(nullptr), right(nullptr) {}
};

int get_size(Node* root) {
    if (root == nullptr) return 0;
    return root->size;
}
void update(Node* root) {
    if (root == nullptr) return;
    root->size = get_size(root->left) + 1 + get_size(root->right);
}

// split by value (for explicit keys)
pair<Node*, Node*> split(Node* root, int v) {
    if (root == nullptr) return {nullptr, nullptr};
    if (root->x <= v) {
        auto res = split(root->right, v);
        root->right = res.first;
        update(root);
        return {root, res.second};
    } else {
        auto res = split(root->left, v);
        root->left = res.second;
        update(root);
        return {res.first, root};
    }
}

// split by size (for implicit keys)
pair<Node*, Node*> split_k(Node* root, int k) {
    if (root == nullptr) return {nullptr, nullptr};
    if (get_size(root) <= k) return {root, nullptr};
    if (k == 0) return {nullptr, root};

    int left_size = get_size(root->left);
    if (left_size >= k) {
        auto res = split_k(root->left, k);
        root->left = res.second;
        update(root);
        return {res.first, root};
    } else {
        auto res = split_k(root->right, k - left_size - 1);
        root->right = res.first;
        update(root);
        return {root, res.second};
    }
}

// merge for both explicit and implicit keys
Node* merge(Node* root1, Node* root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    if (root1->y < root2->y) {
        root1->right = merge(root1->right, root2);
        update(root1);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        update(root2);
        return root2;
    }
}

// insert for explicit keys (use split_k for implicit keys)
Node* insert(Node* root, int v) {
    auto subs = split(root, v);
    return merge(merge(subs.first, new Node(v)), subs.second);
}

// debug helper
void print_node(Node* root, bool end = true) {
    if (root == nullptr) {
        if (end) cout << "\n";
        return;
    }
    print_node(root->left, false);
    cout << root->x << ", ";
    print_node(root->right, false);
    if (end) cout << "\n";
}
