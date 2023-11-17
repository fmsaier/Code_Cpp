#pragma once
#include "Goodgay.h"
#include <iostream>
#include <string>
using namespace std;

class Building
{
	friend class Goodgay;
public:
	Building();
	string m_Livingroom;

private:
	string m_Bedroom;
};
