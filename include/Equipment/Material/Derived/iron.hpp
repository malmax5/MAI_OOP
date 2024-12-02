#pragma once

#include "../Base/material.hpp"

struct Iron : virtual public Material, public CreateLog<Iron>
{
public:
    Iron();
    ~Iron();
};