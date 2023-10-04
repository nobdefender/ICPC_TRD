// Theme: Treap With Segments

// Node
struct node_k {
    int key, priorty, size;
    shared_ptr<node_k> left, right;

    node_k(int key, int priorty = INF) :
        key(key),
        priorty(priorty == INF ?
        reng() : priorty),
        size(1) { }

    friend int sz(shared_ptr<node_k> nd) {
        return (nd ? nd->size : 0ll);
    }

    void upd() {
        size = sz(left) + sz(right) + 1;
    }
};

// Treap
struct treap_k {
    shared_ptr<node_k> root;

    treap_k() { }

    treap_k(int root_key, int root_priorty = INF) {
        root = shared_ptr<node_k>(new node_k(root_key, root_priorty));
    }

    treap_k(shared_ptr<node_k> rt) {
        root = shared_ptr<node_k>(rt);
    }

    treap_k(const treap_k &tr) {
        root = shared_ptr<node_k>(tr.root);
    }

    // Complexity: O(log(N))
    pair<treap_k, treap_k> split_k(int k) {
        auto res = split_k(root, k);
        return { treap_k(res.ff), treap_k(res.ss) };
    }

    pair<shared_ptr<node_k>, shared_ptr<node_k>> split_k(shared_ptr<node_k> rt, int k) {
        if (!rt) return { nullptr, nullptr };
        else if (sz(rt) <= k) return { rt, nullptr };
        else if (sz(rt->left) + 1 <= k) {
            auto [rt1, rt2] = split_k(rt->right, k - sz(rt->left) - 1);
            rt->right = rt1;
            rt->upd();
            return { rt, rt2 };
        }
        else {
            auto [rt1, rt2] = split_k(rt->left, k);
            rt->left = rt2;
            rt->upd();
            return { rt1, rt };
        }
    }

    // Complexity: O(log(N))
    treap_k merge_k(const treap_k &tr) {
        root = shared_ptr<node_k>(merge_k(root, tr.root));
        return *this;
    }

    shared_ptr<node_k> merge_k(shared_ptr<node_k> rt1, shared_ptr<node_k> rt2) {
        if (!rt1) return rt2;
        if (!rt2) return rt1;
        if (rt1->priorty < rt2->priorty) {
            rt1->right = merge_k(rt1->right, rt2);
            rt1->upd();
            return rt1;
        }
        else {
            rt2->left = merge_k(rt1, rt2->left);
            rt2->upd();
            return rt2;
        }
    }
};