#pragma once

#include "../Base/equip.hpp"

struct Helmet : virtual public Equip, public CreateLog<Helmet>
{
public:
    Helmet();
    ~Helmet();
};