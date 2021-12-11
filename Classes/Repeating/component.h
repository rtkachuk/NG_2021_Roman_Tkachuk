#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

struct specs {
	int clock;
	int memory;
};

class Component
{
public:
	Component();

protected:
	void setParameter(int price) { m_price = price; }
	void setParameter(string name) { m_name = name; }
	void setParameter(specs data) { m_data = data; }

	string getName() { return m_name; }
	int getPrice() { return m_price; }
	specs getSpecs() { return m_data; }

private:
	int m_price;
	string m_name;
	specs m_data;
};

#endif // COMPONENT_H
