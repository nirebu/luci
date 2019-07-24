/*
  Copyright (c) 2009 Nicolò Rebughini <nicolo.rebughini@gmail.com>

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc., 51
  Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "displayer.h"

#define FLASHTIME 150

#include <QTimer>
#include <QColor>

Displayer :: Displayer( QWidget *parent )
  : QWidget( parent )
{
  color = QColor( 0 , 0 , 0 );
  stroboState = false;
  blackTime = 1000;
  
  colorTimer = new QTimer( this );
  blackTimer = new QTimer( this );
  
  colorTimer -> setSingleShot( true );
  blackTimer -> setSingleShot( true );
  
  colorTimer -> setInterval( FLASHTIME );
  blackTimer -> setInterval( blackTime );
  
  connect( blackTimer , SIGNAL( timeout() ),
            colorTimer , SLOT( start() ));
  connect( blackTimer , SIGNAL( timeout() ),//funzione di comodo per 
           this , SLOT( setNewInterval() ));//la velocità variabile
  connect( colorTimer , SIGNAL( timeout() ),
            blackTimer , SLOT( start() ));
  connect( blackTimer , SIGNAL( timeout() ),
           this , SLOT( paintColor() ));
  connect( colorTimer , SIGNAL( timeout() ),
           this , SLOT( paintBlack() ));
  
  setAutoFillBackground( true );
  setBackgroundRole( QPalette::Window );
  setPalette( QPalette( color ) );
  resize( 800 , 600 );
}

void Displayer :: toggleStrobo()
{
  if( stroboState )
  {
    disableStrobo();
  }
  else
  {
    enableStrobo();
  }
}

void Displayer :: enableStrobo()
{
  stroboState = true;
  blackTimer -> setInterval( blackTime );
  colorTimer -> start( 100 );
}

void Displayer :: disableStrobo()
{
  stroboState = false;
  blackTimer -> stop();
  colorTimer -> stop();
}

void Displayer :: turnOff()
{
  disableStrobo(); 
  paintBlack();
}

void Displayer :: setSpeed( int newSpeed )
{
  blackTime = 1100 - ( 100 * newSpeed );
}

void Displayer :: paintBlack()
{
  setPalette( QPalette( Qt::black ) );
}

void Displayer :: paintColor()
{
  setPalette( QPalette( color ) );
}

void Displayer :: setColor( QColor newColor )
{
  color = newColor;
  if( !stroboState )
    paintColor();
}

void Displayer :: setNewInterval()
{
  blackTimer -> setInterval( blackTime );
}