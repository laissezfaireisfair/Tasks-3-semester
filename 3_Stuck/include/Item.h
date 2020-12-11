#pragma once
#include <cstdint>
#include <string>

class Item {
    using uint16 = std::uint16_t;
public:
    uint16 id() const;
    std::string name() const;
    uint16 amount() const;
    void add();
    void del();
    bool empty() const;
protected:
    Item(uint16 idIn, std::string const & nameIn, uint16 amountIn);
private:
    uint16 m_id;
    std::string m_name;
    uint16 m_amount;
};