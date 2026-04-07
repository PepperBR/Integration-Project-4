#include "meters/Apolo/Apolo6031.h"
#include "core/GlobalID.h"


Apolo6031::Apolo6031()
    : Apolo(GlobalID::generateID(), "6031")
{
};

Apolo6031::Apolo6031(const Apolo6031& other, int new_id)
    : Apolo(other, new_id) 
{
};

Apolo6031::~Apolo6031()
{
};

std::vector<double> & Apolo6031::getPhaseValues()
{
    return ThreePhaseMeter::getPhaseValues();
};


std::unique_ptr<Meter> Apolo6031::cloneMeter() const
{
    return std::make_unique<Apolo6031>(*this, GlobalID::generateID());
}
