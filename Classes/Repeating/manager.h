#ifndef MANAGER_H
#define MANAGER_H

#include "cpu.h"
#include <vector>

class Manager
{
public:
	Manager();
	void add_Processor(string name);
	void removeProcessor();
	void showProcessors();

private:
	vector<CPU> m_processors;
};

#endif // MANAGER_H
