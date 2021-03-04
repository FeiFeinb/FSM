#pragma once
class BaseEntity
{
public:
	BaseEntity(int _ID) : Entity_ID(_ID) {}
	virtual ~BaseEntity() {}
	virtual void Update() = 0;
	int getID()const { return Entity_ID; }
private:
	int Entity_ID;
};