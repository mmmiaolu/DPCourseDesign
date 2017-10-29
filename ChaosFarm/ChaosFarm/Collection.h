#pragma once
#include "Object.h"

class Collection :public Object
{
public:
	class FarmIterator :public Object
	{
	public:
		friend class Collection;
		virtual Object* value() = 0;
		virtual void turn_next() = 0;
		virtual void turn_previous() = 0;
		virtual void turn_first() = 0;
		virtual void turn_last() = 0;
		virtual bool has_next() = 0;
		virtual bool has_previous() = 0;
		virtual const char* get_class_name(){ return "FarmIterator"; }
	protected:
		Object* current_node_;
	};
	virtual int size() = 0;
	virtual void add(Object* new_element) = 0;
	virtual void remove(FarmIterator* iterator) = 0;
	virtual bool is_empty() = 0;
	virtual void begin(FarmIterator* iterator) = 0;
	virtual void end(FarmIterator* iterator) = 0;
};