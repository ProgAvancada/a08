#include "ofApp.h"


ofApp::ofApp() 
:  ofBaseApp(),
	isDrawingSquare(false), 
	isDrawingCircle(false)
{
    //Utilizamos as fun��es make_unique ou make_shared para criar os smart pointers
    btnCircle = std::make_unique<Button>(100, 100, 100, 50);
	btnSquare = std::make_unique<Button>(300, 100, 100, 50);
}
//--------------------------------------------------------------
void ofApp::setup(){
    //Registramos ofApp como observadora dos dois botoes
    //Observe que uma unica classe (nesse caso ofApp) pode observar dois
    //botoes distintos. E nada nos impediria de cada botao ter seu observer tambem.
    btnCircle->setObserver(this);
    btnSquare->setObserver(this);

    
	btnCircle->setup();
	btnSquare->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    btnCircle->update();
	btnSquare->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	btnCircle->draw();
	btnSquare->draw();

    //Código para realizar o desenho após o botão clicado
	if (isDrawingSquare)
	{
		ofSetColor(0, 0, 255);
		ofDrawRectangle(
			btnSquare->getX(), 
			btnSquare->getY() + btnSquare->getH() + 50, 
			25, 
			25
		);
	}

	if (isDrawingCircle) 
	{
		ofSetColor(255, 0, 0);
		ofDrawCircle(
			btnCircle->getX(), 
			btnCircle->getY() + btnCircle->getH() + 50, 
			25
		);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::onClick(const Button& source)
{
    //Reage ao evento do clique do botao indicando se vai ou nao desenhar o quadrado e o círculo
	if (&source == btnSquare.get()) //Podemos testar no source qual botao foi clicado
	{
		isDrawingSquare = !isDrawingSquare;
	}
	else if (&source == btnCircle.get())
	{
		isDrawingCircle = !isDrawingCircle;
	}

}
