#ifndef VEC2_H
#define VEC2_H

template <class T>
class Vec2 {
    public:
        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}
        T x;
        T y;
};

/**
 * Typedef
 */
typedef Vec2<int> V2i;
typedef Vec2<float> V2f;
typedef Vec2<double> V2d;

#endif
