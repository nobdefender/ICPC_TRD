// Theme: Methematical 3-D Vector

template<typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0): x(x), y(y) {}
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
    T operator*(const Point& other) const {
        return x * other.x + y * other.y;
    }
    T operator/(const Point& other) const {
        return x * other.y - y * other.x;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    T size2() const {
        return x * x + y * y;
    }
    T size() const {
        return sqrt(size2());
    }
    T polar() const {
        return atan2(y, x);
    }
    friend istream& operator>>(istream& in, Point& P) {
        in >> P.x >> P.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Point& P) {
        out << P.x << " " << P.y;
        return out;
    }
};