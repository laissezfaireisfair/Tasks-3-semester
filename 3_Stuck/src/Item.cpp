#include "Item.h"

std::uint16_t Item::id() const {
    return m_id;
}

std::string Item::name() const {
    return m_name;
}

std::uint16_t Item::amount() const {
    return m_amount;
}

void Item::add() {
    ++m_id;
}

void Item::del() {
    if (m_id > 0)
        --m_id;
}

bool Item::empty() const {
    return m_id == 0;
}

Item(std::uint16 idIn, std::string const & nameIn, std::uint16 amountIn) {
    m_id = idIn;
    m_name = nameIn;
    m_amount = amountIn;
}