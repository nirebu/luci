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

#include "colorarray.h"
#include "component.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QColor>
#include <QListWidget>

ColorArray :: ColorArray( QWidget *parent )
  : QWidget(parent)
{
  listaColori = new QListWidget();
  listaColori -> setFixedSize( 85 , 150 );
  
  
  /*QListWidgetItem *nero = new QListWidgetItem( "Nero" , listaColori);
  QListWidgetItem *bianco = new QListWidgetItem( "Bianco" , listaColori);
  QListWidgetItem *rosso = new QListWidgetItem( "Rosso" , listaColori);
  QListWidgetItem *verde = new QListWidgetItem( "Verde" , listaColori);
  QListWidgetItem *blu = new QListWidgetItem( "Blu" , listaColori);*/
  
  red = new Component( "Red" );
  green = new Component( "Green" );
  blue = new Component( "Blue" );
  currentColor = QColor( red -> value() , green -> value() , blue -> value() );
  
  preview = new QWidget();
  
  
  connect( red , SIGNAL( valueChanged( int ) ),
           this, SIGNAL( internalColorChanged() ));
  connect( green , SIGNAL( valueChanged( int ) ),
           this , SIGNAL( internalColorChanged() ));
  connect( blue , SIGNAL( valueChanged( int ) ),
           this , SIGNAL( internalColorChanged() ));
  connect( this , SIGNAL( internalColorChanged() ),
           this , SLOT( updatePreview() ));
 
  
  QGridLayout *layout = new QGridLayout();
  //layout -> addWidget( listaColori , 0 , 0 );
  layout -> addWidget( red , 0 , 1);
  layout -> addWidget( green , 0 , 2 );
  layout -> addWidget( blue , 0 , 3);
  layout -> addWidget( preview , 0 , 4 , 0 , 3 );
  
  preview -> setFixedSize( 150 , 150 );
  preview -> setAutoFillBackground( true );
  preview -> setPalette( QPalette ( Qt::black ) );
  
  setLayout( layout );
}

void ColorArray :: setColor( QColor newColor )
{
  int r = newColor.red();
  int g = newColor.green();
  int b = newColor.blue();
  
  red -> setValue( r );
  green -> setValue( g );
  blue -> setValue( b );
  currentColor.setRgb( r , g , b );
  
  emit colorChanged( currentColor );
}

QColor ColorArray :: color()
{
  currentColor = QColor( red -> value() , green -> value() , blue -> value() );
  return currentColor;
}

void ColorArray :: setRgb( int r , int g , int b )
{
  QColor newColor( r , g , b );
  
  red -> setValue( r );
  green -> setValue( g );
  blue -> setValue( b );
  currentColor.setRgb( r , g , b );
  
  emit colorChanged( currentColor );
}

void ColorArray :: getRgb( int *r , int *g , int *b )
{
  *r = red -> value();
  *g = green -> value();
  *b = blue -> value();
}

void ColorArray :: updatePreview()
{
  preview -> setPalette( QPalette( color() ) );
  
  emit colorChanged( currentColor );
}