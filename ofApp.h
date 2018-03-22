#pragma once

#include "button.h"
#include "ofMain.h"
#include "buttonObserver.h"

#include <memory>

//Observe que ofApp agora implementa a interface ButtonObserver
//E, portanto, tambem define o metodo onClick()
class ofApp : public ofBaseApp, public ButtonObserver {
	private:
        //Uso de smart pointers. O unique_ptr n‹o permite
        //compartilhamento do bot‹o com outras classes.
    
        //O shared_ptr seria a alternativa para permitir
        std::unique_ptr<Button> btnCircle;
		std::unique_ptr<Button> btnSquare;
    
		bool isDrawingSquare;
		bool isDrawingCircle;

	public:
		ofApp();

		void setup();
		void update();
		void draw();

        //Implementacao do metodo onClick da interface ButtonObserver
		virtual void onClick(const Button& source);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
