#include "meters/Apolo/Apolo6031.h"

Apolo6031::Apolo6031()
    : Apolo(1, "6031", Phase::PhaseC){};

Apolo6031::Apolo6031(const Apolo6031 &other, const int &new_id)
    : Apolo(other, new_id){};

Apolo6031::~Apolo6031(){};

std::shared_ptr<Meter> Apolo6031::cloneMeter(int unique_id) const
{
    return std::make_shared<Apolo6031>(*this, unique_id);
}
