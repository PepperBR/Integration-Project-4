#include "meters/Zeus/Zeus8031.h"

Zeus8031::Zeus8031()
    : Zeus(4, "8031", Phase::PhaseC){};

Zeus8031::~Zeus8031(){};

Zeus8031::Zeus8031(const Zeus8031 &other, const int &new_id)
    : Zeus(other, new_id){};

std::shared_ptr<Meter> Zeus8031::cloneMeter(int unique_id) const
{
    return std::make_shared<Zeus8031>(*this, unique_id);
}
