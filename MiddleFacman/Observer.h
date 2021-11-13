#pragma once
#include <combaseapi.h>

class GhostManager;

interface Observer
{
public:
	virtual void updata(GhostManager* gm) = 0;
};