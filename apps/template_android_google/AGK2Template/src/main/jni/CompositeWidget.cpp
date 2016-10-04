#include "CompositeWidget.h"

CompositeWidget::CompositeWidget()
{
    //ctor
}
CompositeWidget::CompositeWidget(const Vector2& position, const Vector2& size)
    : Widget(position, size)
{

}
CompositeWidget::CompositeWidget(XMLNode* node)
    : Widget(node) {

}
CompositeWidget::~CompositeWidget() {
    //dtor
}
void CompositeWidget::AddWidget(Widget* widget) {
    mChildren.push_back(widget);
}

void CompositeWidget::RemoveWidget(const string& name) {

}

Widget* CompositeWidget::GetWidget(const string& name) {

}

void CompositeWidget::OnInitialize() {
    std::vector<Widget*>::iterator it = mChildren.begin();
    while(it != mChildren.end()){
        (*it)->Initialize();
        it++;
    }
}

void CompositeWidget::Update()
{
    std::vector<Widget*>::iterator it = mChildren.begin();
    while(it != mChildren.end()){
        (*it)->Update();
        it++;
    }
}
string CompositeWidget::dump() const{
    stringstream ss;
    ss << *this;
    std::vector<Widget*>::const_iterator it = mChildren.begin();
    while(it != mChildren.end()){
        ss << (*it)->dump();
        it++;
    }
    return ss.str();
}
void CompositeWidget::Print() {
    ALOGD("CompositeWidget", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const CompositeWidget& compositeWidget){
    // add to stream
    return stream;
}

