#include "afx.h"
SplashView::SplashView(){
	m_pSplashImage = NULL;

}

SplashView::~SplashView(){
}

void SplashView::onUpdate(double frameTime){
	
}
void SplashView::onCreate(){
	TxBatteryMeterWidget *pWidget = new TxBatteryMeterWidget();
	addWidget(new TxBatteryMeterWidget());
}
void SplashView::onRender(double frameTime){
}

