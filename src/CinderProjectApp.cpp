#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CinderProjectApp::setup()
{

}

void CinderProjectApp::mouseDown( MouseEvent event )
{

}

void CinderProjectApp::update()
{
}

void CinderProjectApp::draw()
{
	gl::clear( Color( 0, 0.6f, 0.7f ) ); 
}

CINDER_APP( CinderProjectApp, RendererGl )
