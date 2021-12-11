#include "manager.h"

Manager::Manager()
{

}

void Manager::add_Processor(string name)
{
	CPU newcpu;
	newcpu.setName(name);
	m_processors.push_back(newcpu);
}

void Manager::removeProcessor()
{

}

void Manager::showProcessors()
{
	for (CPU bufferCPU : m_processors) {
		cout << "===========================" << endl;
		bufferCPU.showInfo();
	}
	cout << "===========================" << endl;
}
