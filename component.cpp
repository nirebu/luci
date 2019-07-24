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

#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>

#include "component.h"


//Component Constructor
Component :: Component( const QString &text , int minimum , int maximum , QWidget *parent )
  : QWidget(parent)
{
  label = new QLabel( text );
  slider = new QSlider( Qt::Vertical );
  spinbox = new QSpinBox();
  
  slider -> setRange( minimum , maximum );
  slider -> setTickInterval( qRound( ( maximum - minimum ) / 10 ) );
  slider -> setTickPosition( QSlider::TicksBothSides );
  spinbox -> setRange( minimum , maximum );
  
  connect( slider , SIGNAL( valueChanged( int ) ) , 
           this , SIGNAL( valueChanged( int ) ));
  connect( slider , SIGNAL( valueChanged( int ) ) ,
           spinbox , SLOT( setValue( int ) ));
  connect( spinbox , SIGNAL( valueChanged( int ) ) ,
           slider , SLOT( setValue( int ) ));
  
  QVBoxLayout *layout = new QVBoxLayout();
  layout -> addWidget( label , 0 , Qt::AlignHCenter );
  layout -> addWidget( spinbox , 0 , Qt::AlignHCenter );
  layout -> addWidget( slider , 0 , Qt::AlignHCenter );
  
  setLayout( layout );
}

void Component :: setValue( int newValue )
{
  slider -> setValue( newValue );
  emit valueChanged( newValue );
}