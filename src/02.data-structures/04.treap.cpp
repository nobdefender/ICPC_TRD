// Theme: Treap (Tree + Heap)

// Node
struct node {
    int key, priorty;
    shared_ptr<node> left, right;

    node(int key, int priorty = INF) :
        key(key),
        priorty(priorty == INF ?
        reng() : priorty) { }
};

// Treap
struct treap {
    shared_ptr<node> root;

    treap() { }

    treap(int root_key, int root_priorty = INF) {
        root = shared_ptr<node>(new node(root_key, root_priorty));
    }

    treap(shared_ptr<node> rt) {
        root = shared_ptr<node>(rt);
    }

    treap(const treap &tr) {
        root = shared_ptr<node>(tr.root);
    }

    // Complexity: O(log(N))
    pair<treap, treap> split(int k) {
        auto res = split(root, k);
        return { treap(res.ff), treap(res.ss) };
    }

    pair<shared_ptr<node>, shared_ptr<node>> split(shared_ptr<node> rt, int k) {
        if (!rt) return { nullptr, nullptr };
        else if (rt->key < k) {
            auto [rt1, rt2] = split(rt->right, k);
            rt->right = rt1;
            return { rt, rt2 };
        }
        else {
            auto [rt1, rt2] = split(rt->left, k);
            rt->left = rt2;
            return { rt1, rt };
        }
    }

    // Complexity: O(log(N))
    treap merge(const treap &tr) {
        root = shared_ptr<node>(merge(root, tr.root));
        return *this;
    }

    shared_ptr<node> merge(shared_ptr<node> rt1, shared_ptr<node> rt2) {
        if (!rt1) return rt2;
        if (!rt2) return rt1;
        if (rt1->priorty < rt2->priorty) {
            rt1->right = merge(rt1->right, rt2);
            return rt1;
        }
        else {
            rt2->left = merge(rt1, rt2->left);
            return rt2;
        }
    }
};