#pragma once
#include "Observer.h"
#include <combaseapi.h>

interface Subject
{
public:
	virtual void registerObserver(Observer* ob) = 0;
	virtual void removeObserver(Observer* ob) = 0;
	virtual void notifyObserver() = 0;
};