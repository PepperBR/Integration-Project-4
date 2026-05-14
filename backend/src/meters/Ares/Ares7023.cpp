#include "meters/Ares/Ares7023.h"

Ares7023::Ares7023()
    : Ares(14, "7023", Phase::PhaseB){};

Ares7023::Ares7023(const Ares7023 &other, const int &new_id)
    : Ares(other, new_id){};

Ares7023::~Ares7023(){};

std::shared_ptr<Meter> Ares7023::cloneMeter(int unique_id) const
{
    return std::make_shared<Ares7023>(*this, unique_id);
}
