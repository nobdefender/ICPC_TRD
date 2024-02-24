#define ll __int128
 
const ll inf = 2e18;
struct line {
    ll k, b;
    line() {}
    line(ll a, ll _b) { k = a, b = _b; }
    ll get(ll x) { return k * x + b; }
};
 
vector<line> lines; // храним прямые нижней огибающей
vector<ll> dots; // храним x-координаты точек нижней огибающей
//     ^ первое правило вещественных чисел
//      считаем, что в dots лежит округленная вниз x-координата
 
ll cross(line a, line b) { // считаем точку пересечения
    // считаем a.k > b.k
    ll x = (b.b - a.b) / (a.k - b.k);
    if (b.b < a.b) x--; // боремся с округлением у отрицательных чисел
    return x;
}
 
void add(line cur) {
    while (lines.size() && lines.back().get(dots.back()) > cur.get(dots.back())) {
        lines.pop_back();
        dots.pop_back();
    }
    if (lines.empty()) {
        dots.push_back(-inf);
    }
    else
        dots.push_back(cross(lines.back(), cur));
 
    lines.push_back(cur);
}
 
ll get(ll x) {
    int pos = lower_bound(dots.begin(), dots.end(), x) - dots.begin() - 1;
    return lines[pos].get(x);
}

//if dp[i] = max(a[i]*dp[j] + b[j]), then make a lines with k = dp[j], b = b[j] and get min on x = a[i]
