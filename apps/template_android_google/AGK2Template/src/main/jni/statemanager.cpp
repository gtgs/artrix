#include "statemanager.h"
#include <android/log.h>
StateManager::StateManager()
{

}
StateManager::~StateManager()
{

}
StateManager* StateManager::GetInstance()
{
    if(0 == m_instance)
        m_instance = new StateManager();
    return m_instance;
}
void StateManager::DestroyInstance()
{
    delete(m_instance);
}
void StateManager::GotoState(StateMachine* sm, State* newState)
{
    __android_log_print(ANDROID_LOG_DEBUG, "StateManager", "changing state");
    if(0 == newState)
    {
        return;
    }
    State* state = sm->GetCurrentState();
    if(0 != state){
        state->Exit(sm);
    }
    sm->SetPreviousState(state);
    sm->SetCurrentState(newState);
    if(!newState->GetIsOneTimeEntered()){
        newState->OneTimeEnter(sm);
    }
    newState->Enter(sm);
}
StateManager* StateManager::m_instance = 0;
