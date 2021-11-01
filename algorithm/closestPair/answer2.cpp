#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N;
struct Point {
    double x;
    double y;
    Point(double x, double y) {
        this->x = x;this->y = y;
    }
};

double split_line;


bool comp1(const Point& p1, const Point& p2) {
    if(p1.x == p2.x) {
        return p1.y <= p2.y;
    } else
        return p1.x <= p2.x;
}

bool comp2(const Point& p1, const Point& p2) {
    if(p1.y == p2.y) {
        return p1.x <= p2.x;
    } else
        return p1.y <= p2.y;
}

vector<Point> points;

void merge() {

}


double closePair(int from, int length) {
    
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        points.emplace_back(new Point(x, y));
    }
    sort(points.begin(), points.end(), comp1);
    int length = points.size();
    
    printf("%lf", closePair(0, points.size()));
    return 0;
}