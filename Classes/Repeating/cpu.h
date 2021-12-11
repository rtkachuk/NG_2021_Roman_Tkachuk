#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "component.h"

enum ARCH {
	NOARCH,
	X86,
	AMD64,
	ARM,
	ARM64,
	POWERPC,
	SPARC
};

class CPU : public Component
{
public:
	CPU();
	void showInfo();
	void setArch(ARCH arch) { m_cpu_arch = arch; }
	void setName(string name) { setParameter(name); }

	string getArch();
	string getName() { return Component::getName(); }

private:
	ARCH m_cpu_arch;
};

#endif // CPU_H
