#include "UnitTool.h"

#define DEBUG

const int initDurabilityUnit = 1;

UnitTool::UnitTool(string name)
	:Tool(name), durabilityUnit_(initDurabilityUnit)
{
}


UnitTool::UnitTool(vector<Abstract*>* abs_list, int size,string name, int init_durability, MaterialType material)
	:Tool(abs_list, size, name, init_durability, material), durabilityUnit_(initDurabilityUnit)
{
}


UnitTool::~UnitTool()
{
}

void UnitTool::update(AbstractType type)
{

}

void UnitTool::outputDurability()
{
#ifdef DEBUG
	cout << "��(" << this->getName() << ")��ǰ�;ö�" << durability_ << endl;
#endif // DEBUG
}

void UnitTool::loss()
{
	durability_ -= durabilityUnit_;
#ifdef DEBUG
	cout << "��(" << this->getName() << ")ĥ���� " << durabilityUnit_ << "���;ö�����" << endl;
	outputDurability();
#endif //DEBUG
}

void UnitTool::fix(int n)
{
	durability_ += n;
#ifdef DEBUG
	cout << "��(" << this->getName() << ")�������� " << n << " ���;ö�����" << endl;
	outputDurability();
#endif // DEBUG
}

