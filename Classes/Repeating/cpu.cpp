#include "cpu.h"

CPU::CPU()
{
	setParameter(0);
	setParameter("NONAME");
	setParameter(specs{0,0});
	setArch(ARCH::NOARCH);
}

void CPU::showInfo()
{
	cout << "NAME: " << getName() << endl
		 << "PRICE: " << getPrice() << endl
		 << "ARCH: " << getArch() << endl;
}

string CPU::getArch() {
	switch(m_cpu_arch) {
		case NOARCH: return "NO ARCH SPECIFIED";
		case X86: return "X86/i386";
		case AMD64: return "AMD64";
		case ARM: return "ARMv7";
		case ARM64: return "ARMv8";
		case POWERPC: return "PowerPC";
		case SPARC: return "SUN SPARC";
		default: return "ERROR: NO DEFINED";
	}
}
