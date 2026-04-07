#include "meters/Ares/Ares7031.h"
#include "core/GlobalID.h"


Ares7031::Ares7031()
    : Ares(GlobalID::generateID(), "7031")
{
};


Ares7031::Ares7031(const Ares7031& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares7031::~Ares7031()
{
};

std::vector<double> & Ares7031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7031::cloneMeter() const
{
    return std::make_unique<Ares7031>(*this, GlobalID::generateID());
}

