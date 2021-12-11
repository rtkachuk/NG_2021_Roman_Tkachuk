#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
	Manager manager;
	manager.add_Processor("TEST1");
	manager.add_Processor("TEST2");
	manager.showProcessors();
	return 0;
}
