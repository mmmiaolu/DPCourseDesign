#ifndef CF_FARMLAND_H
#define CF_FARMLAND_H
#include <iostream>
#include <string>
#include<vector>
#include"Facility.h"
#include"Time.h"
#include"Atmosphere.h"
#include "AbstractType.h"
#include "Crop.h"

using namespace std;

class Crop;

//ʹ��Decorator����Farmland����Ĺ��ܽ��а�װ��չ

class BaseFarmLand:public Facility{
public:
	BaseFarmLand(vector<Abstract*>* abs, int size, int duarability, const char* desc, float fertility = 1)
		:Facility(abs, size, duarability), fertility_(fertility)
	{
		description_ = new string(desc);
	}

	BaseFarmLand(BaseFarmLand* farmland)
		:Facility(NULL, farmland->size(),farmland->get_durability())
	{
		description_ = new string;
		set_discription(farmland->get_discription());
		set_fertility(farmland->get_fertility());
	}

	~BaseFarmLand(){ delete description_; }

	virtual const char* get_discription() const { return description_->c_str(); }

	virtual void set_discription(const char* str){ (*description_) = string(str); }

	virtual int size() { return size_; }


	virtual void when_atmosphere_changed(){
		cout << "smell changed."<<endl;
	}

	virtual void time_pass_by() {}

	virtual void update(AbstractType type){ 
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}

	float get_fertility(){ return fertility_; }

	void set_fertility(float fertility){ fertility_ = fertility; }

	virtual void plant_a_crop(Crop* crop);

	virtual const char* get_class_name(){ return "BaseFarmLand"; }
protected:

	string* description_;			//�����ַ���

	float fertility_;				//���ֶ�
};

//��BaseFarmLand�Ļ����Ͻ���װ�Σ�������plow���ܵ�Farmland
class FarmLand :public BaseFarmLand{
public:
	FarmLand(BaseFarmLand* baseFarmland) :BaseFarmLand(baseFarmland){}

	FarmLand(FarmLand* farmland) :BaseFarmLand(farmland){}

	~FarmLand(){}

	//��غ�������������ũ��ķ��ֶȣ�n��ʾ��صĴ�����Ĭ��n = 1
	void plow(int n = 1){ fertility_ += n; }

	virtual void plant_a_crop(Crop* crop){ BaseFarmLand::plant_a_crop(crop); }

	virtual const char* get_class_name(){ return "FarmLand"; }
};


//��Farmland�Ļ����Ͻ���װ�Σ��������ɷ��ֶ�Ӱ����ֲ�������ֲ��Ľ�ʵ�ʵĹ���
class EffectFarmLand :public FarmLand{
public:
	EffectFarmLand(FarmLand* baseFarmland) :FarmLand(baseFarmland){}

	EffectFarmLand(EffectFarmLand* farmland) :FarmLand(farmland){}

	~EffectFarmLand(){}

	virtual void plant_a_crop(Crop* crop);
	virtual const char* get_class_name(){ return "EffectFarmLand"; }
};


#endif