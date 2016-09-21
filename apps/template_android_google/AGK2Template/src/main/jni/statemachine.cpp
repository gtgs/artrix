#include "statemachine.h"
#include "statemanager.h"
#include <android/log.h>
StateMachine::StateMachine(){
    mCurrentState = NULL;
    mPreviousState = NULL;
}
StateMachine::~StateMachine(){
    delete(mCurrentState);
    delete(mPreviousState);
}
State* StateMachine::GetCurrentState(){
    return mCurrentState;
}
void StateMachine::SetCurrentState(State* newState){
    mCurrentState = newState;
}

State* StateMachine::GetPreviousState(){
    return mPreviousState;
}
void StateMachine::SetPreviousState(State* newState){
    mPreviousState = newState;
}

void StateMachine::GotoState(State* newState) {
    __android_log_print(ANDROID_LOG_DEBUG, "StateMachine::GotoState", "attempting change state...");
    if(NULL == newState){
        __android_log_print(ANDROID_LOG_DEBUG, "StateMachine::GotoState", "cannot change state, state is null");
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "StateMachine::GotoState", "state transition from %s to %s", (mCurrentState != NULL) ? mCurrentState->GetName().c_str() : "NULL", (newState != NULL) ? newState->GetName().c_str() : "NULL");
    if(NULL != mCurrentState) {
        if (mCurrentState->GetIsTerminable() != true){
            __android_log_print(ANDROID_LOG_DEBUG, "StateMachine::GotoState", "cannot change state, current state is non-terminable");
            return;
        }
        mCurrentState->Exit(this);
    }
    mPreviousState = mCurrentState;
    mCurrentState = newState;
    if(!mCurrentState->GetIsOneTimeEntered()) {
        mCurrentState->OneTimeEnter(this);
    }
    mCurrentState->Enter(this);
    __android_log_print(ANDROID_LOG_DEBUG, "StateMachine::GotoState", "state transition from %s to %s", (mPreviousState!= NULL) ? mPreviousState->GetName().c_str() : "NULL", (mCurrentState != NULL) ? mCurrentState->GetName().c_str() : "NULL");
}
