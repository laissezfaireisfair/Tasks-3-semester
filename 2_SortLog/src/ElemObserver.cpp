#include "ElemObserver.h"
#include "Ui.h"

static void ElemObserver::comparsion_happened(Elem const & left, Elem const & right) {
    Ui::print_comparsion(left.get_value(), right.get_value());
}
