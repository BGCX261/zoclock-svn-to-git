/*
 * Copyright 2009 Alexey Michurin
 * 
 * This file is part of ZOClock.
 * 
 * ZOclock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ZOclock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with ZOClock. If not, see <http://www.gnu.org/licenses/>.
 */

#include "zocdot.h"
#include "zoclock.h"

BinClockDot::BinClockDot(QWidget *parent)
    : Inherited(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setLineWidth(ZOC_WINDOW_BORDER);
    setAutoFillBackground(true);
}
