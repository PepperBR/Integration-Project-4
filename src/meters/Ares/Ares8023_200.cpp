#include "meters/Ares/Ares8023_200.h"

Ares8023_200::Ares8023_200()
    : Ares(17, "8023 200"){};

Ares8023_200::Ares8023_200(const Ares8023_200 &other, int new_id)
    : Ares(other, new_id){};

Ares8023_200::~Ares8023_200(){};

std::vector<double> &Ares8023_200::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Ares8023_200::cloneMeter(int unique_id) const
{
    return std::make_shared<Ares8023_200>(*this, unique_id);
}
