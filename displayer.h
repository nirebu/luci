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

#ifndef DISPLAYER_H
#define DISPLAYER_H

#include <QWidget>

class QColor;
class QTimer;

class Displayer : public QWidget{
  Q_OBJECT
  
  public:
    Displayer( QWidget *parent = 0 );
  public slots:
    void toggleStrobo();
    void turnOff();
    void setSpeed( int newSpeed );
    
    void setColor( QColor newColor );
    
    void paintBlack();
    void paintColor();
    void setNewInterval();
  private:
    void enableStrobo();
    void disableStrobo();
    
    QColor color;
    bool stroboState;
    int blackTime;
    
    QTimer *colorTimer;
    QTimer *blackTimer;
};

#endif
