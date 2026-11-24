// example.cpp -- one sample, every theme
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX_SHAPES 16
#define SQUARE(x) ((x) * (x))

/* A tiny shape hierarchy:
 * Shape <- Circle
 */
namespace geometry {

constexpr double kPi = 3.14159265358979;

struct Point {
    double x = 0.0, y = 0.0;
};

class Shape {
public:
    explicit Shape(std::string name) : name_(std::move(name)) {}
    virtual ~Shape() = default;
    virtual double area() const = 0;
    const std::string& name() const { return name_; }

protected:
    std::string name_;
};

class Circle : public Shape {
public:
    Circle(Point c, double r) : Shape("circle"), c_(c), r_(r) {}
    double area() const override { return kPi * SQUARE(r_); }

private:
    Point c_;
    double r_;
};

}  // namespace geometry

template <typename T>
T largest(const std::vector<T>& items) {
    T best = items.front();  // TODO: handle empty input
    for (const auto& it : items)
        if (it > best) best = it;
    return best;
}

int main() {
    std::vector<std::unique_ptr<geometry::Shape>> shapes;
    std::unordered_map<std::string, int> counts;
    shapes.push_back(std::make_unique<geometry::Circle>(
        geometry::Point{0, 0}, 2.5f));

    double total = 0.0;
    for (size_t i = 0; i < shapes.size(); ++i) {
        total += shapes[i]->area();
        counts[shapes[i]->name()]++;
    }
    if (total > 0x1F && counts.size() < MAX_SHAPES) {
        std::cout << "Total area: " << total << '\n';
    } else {
        std::cerr << "too \"small\"\n";
    }
    return 0;
}
