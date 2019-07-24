#include "colorarray.h"
#include "stroboarray.h"
#include "displayer.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

int main( int argc , char *argv[] )
{
  QApplication app( argc , argv );
  
  ColorArray *colorArray = new ColorArray();
  StroboArray *stroboArray = new StroboArray();
  Displayer *displayer = new Displayer();
  
  QWidget controlWidget;
  QVBoxLayout *layout = new QVBoxLayout();
  
  layout -> addWidget( colorArray );
  layout -> addWidget( stroboArray );
  
  QObject::connect( stroboArray , SIGNAL( speedChanged( int ) ),
                    displayer , SLOT( setSpeed( int ) ));
  QObject::connect( stroboArray , SIGNAL( toggleStrobo() ),
                    displayer , SLOT( toggleStrobo() ));
  QObject::connect( colorArray , SIGNAL( colorChanged( QColor ) ),
                    displayer , SLOT( setColor( QColor ) ));
  QObject::connect( stroboArray , SIGNAL( turnOff() ),
                    displayer , SLOT( turnOff() ));

  controlWidget.setLayout( layout );
  controlWidget.resize( 370 , 400 );
  controlWidget.show();
  displayer -> show();
  
  return app.exec();
}
