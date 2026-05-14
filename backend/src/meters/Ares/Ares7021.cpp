#include "meters/Ares/Ares7021.h"

Ares7021::Ares7021()
    : Ares(12, "7021", Phase::PhaseA){};

Ares7021::Ares7021(const Ares7021 &other, const int &new_id)
    : Ares(other, new_id){};

Ares7021::~Ares7021(){};

std::shared_ptr<Meter> Ares7021::cloneMeter(int unique_id) const
{
    return std::make_shared<Ares7021>(*this, unique_id);
}
