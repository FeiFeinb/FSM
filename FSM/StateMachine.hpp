#pragma once
#include"State.h"
#include"Motion.h"
template<class EntityType>
class State;
template<class EntityType>
class StateMachine
{
private:
	EntityType* pOwner;

	State<EntityType>* pPreviousState;
	State<EntityType>* pCurrentState;
	State<EntityType>* pGlobolState;
public:
	StateMachine(EntityType* _pOwner) : pOwner(_pOwner), pPreviousState(nullptr), 
		pCurrentState(nullptr), pGlobolState(nullptr) {}

	void SetPreviousState(State<EntityType>* _pState) { pPreviousState = _pState; }
	void SetCurrentState(State<EntityType>* _pState) { pCurrentState = _pState; }
	void SetGlobalState(State<EntityType>* _pState) { pGlobolState = _pState; }
	State<EntityType>* PreviousState() const { return pPreviousState; }
	State<EntityType>* CurrentState() const { return pCurrentState; }
	State<EntityType>* GlobalState() const { return pGlobolState; }
	bool isInState(const State<EntityType>* _pState) const { return pCurrentState == _pState; }
	void ChangeState(State<EntityType>* _pState);
	void ToPrevious();
	void Update() const;
};


template<class EntityType>
inline void StateMachine<EntityType>::ChangeState(State<EntityType>* _pState)
{
	assert(pCurrentState && _pState);
	pCurrentState->Exit(pOwner);
	pCurrentState = _pState;
	pCurrentState->Enter(pOwner);
}

template<class EntityType>
inline void StateMachine<EntityType>::ToPrevious()
{
	ChangeState(pPreviousState);
}

template<class EntityType>
inline void StateMachine<EntityType>::Update() const
{
	if (pGlobolState)
		pGlobolState->Excute(pOwner);
	if (pCurrentState)
		pCurrentState->Excute(pOwner);
}
