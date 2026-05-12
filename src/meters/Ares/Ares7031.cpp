#include "meters/Ares/Ares7031.h"

Ares7031::Ares7031()
    : Ares(15, "7031"){};

Ares7031::Ares7031(const Ares7031 &other, int new_id)
    : Ares(other, new_id){};

Ares7031::~Ares7031(){};

std::vector<double> &Ares7031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::shared_ptr<Meter> Ares7031::cloneMeter(int unique_id) const
{
    return std::make_shared<Ares7031>(*this, unique_id);
}
