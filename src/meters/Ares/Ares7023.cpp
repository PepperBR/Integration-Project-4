#include "meters/Ares/Ares7023.h"
#include "core/GlobalID.h"


Ares7023::Ares7023()
    : Ares(GlobalID::generateID(), "7023")
{
};


Ares7023::Ares7023(const Ares7023& other, int new_id)
    : Ares(other, new_id) 
{
};

Ares7023::~Ares7023()
{
};

std::vector<double> & Ares7023::getPhaseValues()
{
    return TwoPhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Ares7023::cloneMeter() const
{
    return std::make_unique<Ares7023>(*this, GlobalID::generateID());
}

