#include <android/log.h>
#include <algorithm>
#include "artrix.h"
#include "agk.h"

#include "Managers.h"
using namespace AGK;
using namespace std;
Artrix::Artrix(){

}

Artrix::~Artrix(){
    //dtor
}
void Artrix::Begin()
{
    agk::SetVirtualResolution (Managers::MM->GetResolution().x, Managers::MM->GetResolution().x);
    agk::SetClearColor( 0, 0, 0); // black
    agk::SetSyncRate(60,0);
    agk::SetScissor(0,0,0,0);
    agk::SetOrientationAllowed(0, 0, 1, 1);
    Managers::SM->GotoState(this, new ArtrixHomeState());
}

void Artrix::Loop()
{
    mCurrentState->Update(this, 0);
}
void Artrix::End()
{
}

ArtrixHomeState::ArtrixHomeState()
    : State("Home"){

}


ArtrixHomeState::~ArtrixHomeState(){
}

void ArtrixHomeState::OnOneTimeEnter(const StateMachine* sm)
{
    vector<Screen*> screens = Managers::CM->GetScreens();

//    vector<Screen*>::const_iterator it = screens.begin();
//    while(it != screens.end()) {
//        (*it)->Print();
//        it++;
//    }
//    Screen* s = new Screen("home");
//    vector<Screen*>::iterator screen = std::find(screens.begin(), screens.end(), s);
//    mHomeScreen = *screen;
}

void ArtrixHomeState::Update(const StateMachine* sm, double gameTime){
    //mHomeScreen->Update();
    //__android_log_print(ANDROID_LOG_DEBUG, "test", "count is %d", Configuration::GetScreens().size());
}
