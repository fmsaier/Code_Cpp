#include"Building.h"
Goodgay::Goodgay()
{
	building = new Building;
}
void Goodgay::visit()
{
	cout << "visit正在访问:" << building->m_Livingroom << endl;
	cout << "visit正在访问:" << building->m_Bedroom << endl;
}