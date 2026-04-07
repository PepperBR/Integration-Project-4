#include "meters/Ares/Ares8023_200.h"
#include "core/GlobalID.h"


Ares8023_200::Ares8023_200()
    : Ares(GlobalID::generateID(), "8023 200")
{
};

Ares8023_200::Ares8023_200(const Ares8023_200& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares8023_200::~Ares8023_200()
{
};

std::vector<double> & Ares8023_200::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares8023_200::cloneMeter() const
{
    return std::make_unique<Ares8023_200>(*this, GlobalID::generateID());
}
