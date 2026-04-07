#include "meters/Ares/Ares8023.h"
#include "core/GlobalID.h"


Ares8023::Ares8023()
    : Ares(GlobalID::generateID(), "8023")
{
};

Ares8023::Ares8023(const Ares8023& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares8023::~Ares8023()
{
};

std::vector<double> & Ares8023::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};

std::unique_ptr<Meter> Ares8023::cloneMeter() const
{
    return std::make_unique<Ares8023>(*this, GlobalID::generateID());
}


