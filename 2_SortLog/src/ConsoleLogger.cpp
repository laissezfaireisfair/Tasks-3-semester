#include <iostream>
#include "ConsoleLogger.h"
#include "Operation.h"
#include "ELem.h"

ConsoleLogger::ConsoleLogger() {
    m_operations = std::vector<Operation*>();
}

void ConsoleLogger::operation_happened(const Operation &operation) {
    auto *operationPtr = new Operation(operation);
    m_operations.push_back(operationPtr);
}

void ConsoleLogger::print_operations() const {
    for (auto & operation : m_operations) {
        std::cout << operation->get_description() << " between " << operation->get_left_elem_position() << " and ";
        std::cout << operation->get_right_elem_position() << std::endl;
    }
}

void ConsoleLogger::print_vec(std::vector<Elem> const & vec) {
    for (auto & elem : vec)
        std::cout << elem.value() << " ";
    std::cout << std::endl;
}