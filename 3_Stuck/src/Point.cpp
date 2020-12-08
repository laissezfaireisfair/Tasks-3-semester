#include "Point.h"

Point::Point(size_t const xIn, size_t const yIn) :
    m_x(xIn),
    m_y(yIn) {}

size_t const & Point::x() const {
    return m_x;
}

size_t const & Point::y() const {
    return m_y;
}

void Point::set_x(size_t const x) {
    m_x = x;
}

void Point::set_y(size_t const y) {
    m_y = y;
}