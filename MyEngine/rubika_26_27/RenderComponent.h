#pragma once
#include <vector>

#include "IDrawable.h"
#include "Rectangle.h"

class RenderComponent
{
public:
    std::vector<IDrawable*> drawables;
};
