#pragma once

/// Point describes the place in field
class Point {
public:
    Point(size_t xIn, size_t yIn);

    size_t const & x() const;

    size_t const & y() const;

    void set_x(size_t xNew);

    void set_y(size_t yNew);
private:
    size_t m_x;
    size_t m_y;
};
