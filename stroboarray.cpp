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

#include "stroboarray.h"
#include "component.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

StroboArray :: StroboArray( QWidget *parent )
  : QWidget( parent )
{
  
  speed = new Component( "Speed" , 1 , 10 );
  
  toggleStroboButton = new QPushButton("Strobo");
  QPushButton *turnOffButton = new QPushButton("Spegni tutto");
  
  connect( toggleStroboButton , SIGNAL( clicked() ),
           this , SIGNAL( toggleStrobo() ));
  connect( speed , SIGNAL( valueChanged( int ) ),
           this , SIGNAL( speedChanged( int ) ));
  connect( turnOffButton , SIGNAL( clicked() ),
           this , SIGNAL( turnOff() ));
  
  QHBoxLayout *layout = new QHBoxLayout();
  layout -> addWidget( speed );
  
  QVBoxLayout *buttonLayout = new QVBoxLayout();
  buttonLayout -> addWidget( toggleStroboButton );
  buttonLayout -> addWidget( turnOffButton );
  
  layout -> addLayout( buttonLayout );
  
  setLayout( layout );
}