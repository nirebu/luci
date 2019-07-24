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

#ifndef COLORARRAY_H
#define COLORARRAY_H

#include <QWidget>
#include <QListWidgetItem>

class Component;
class QColor;
class QListWidget;

class ColorArray : public QWidget{
  Q_OBJECT
  
  public:
    ColorArray( QWidget *parent = 0 );
    QColor color();
    void getRgb( int *r , int *g , int *b );
  public slots:
    void setColor( QColor newColor );
    void setRgb( int r , int g , int b );
    void updatePreview();
  signals:
    void internalColorChanged();
    void colorChanged( QColor newc );
  private:
   
    QListWidget *listaColori;
    Component *red;
    Component *green;
    Component *blue;
    QColor currentColor;
    QWidget *preview;
};

/*class ColorListItem : QListWidgetItem{
  public:
    //ColorListItem( const QString &text , int r , int g , int b , QWidget *parent = 0);
  private:
    int r;
    int g;
    int b;
};*/

#endif
