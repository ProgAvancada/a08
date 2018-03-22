#include "button.h"
#include "ofMain.h"

Button::Button(float px, float py, float width, float height)
	: x(px), y(py), w(width), h(height), isDown(false)
{
}


void Button::setup()
{
	
}
void Button::draw()
{
	ofSetColor(isDown ? 220 : 255);
	ofDrawRectangle(x, y, w, h);
}

bool Button::isHovered() 
{
	float mx = ofGetMouseX();
	float my = ofGetMouseY();

	return (mx >= x && mx <= x + w &&
		my >= y && my <= y + h);
}

void Button::update()
{
	if (isDown && !ofGetMousePressed(OF_MOUSE_BUTTON_1))
	{
		fireButtonClicked();
		isDown = false;
		return;
	}

	if (!isDown && isHovered() && ofGetMousePressed(OF_MOUSE_BUTTON_1))
	{
		isDown = true;
	}
}

void Button::fireButtonClicked() 
{
    if (observer == nullptr) {
        return;
    }
    
    observer->onClick(*this);
}

void Button::setObserver(ButtonObserver* observer)
{
	this->observer = observer;
}
