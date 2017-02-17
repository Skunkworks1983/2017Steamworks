#include "./cPIDOutputContainer.h"

cPIDOutputContainer::cPIDOutputContainer()
{
	m_value = 0;
}

cPIDOutputContainer::~cPIDOutputContainer()
{

}

void cPIDOutputContainer::PIDWrite(double value)
{
	this->m_value = value;
}

double cPIDOutputContainer::getVal()
{
	return m_value;
}
