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

#include "popupmenu.h"

PopupMenu::PopupMenu(QWidget * parent)
    : Inherited(parent)
{
    QAction* a;
    addSeparator();
    a = new QAction(tr("Lock window position"), this);
    a->setCheckable(true);
    addAction(a);
    lock_pos = a;
    a = new QAction(tr("Keep window always on top"), this);
    a->setCheckable(true);
    addAction(a);
    connect(a, SIGNAL(triggered()), parent, SLOT(menu_ontop()));
    window_ontop = a;
    addSeparator();
    a = new QAction(tr("Color of \"0\" indicator"), this);
    addAction(a);
    connect(a, SIGNAL(triggered()), this, SLOT(color_0()));
    a = new QAction(tr("Color of \"1\" indicator"), this);
    addAction(a);
    connect(a, SIGNAL(triggered()), this, SLOT(color_1()));
    a = new QAction(tr("Restore original colors"), this);
    addAction(a);
    connect(a, SIGNAL(triggered()), parent, SLOT(menu_oem_colors()));
    addSeparator();
    a = new QAction(tr("Save current settings as default"), this);
    addAction(a);
    connect(a, SIGNAL(triggered()), parent, SLOT(menu_save_setings()));
    addSeparator();
    a = new QAction(tr("About"), this);
    connect(a, SIGNAL(triggered()), parent, SLOT(menu_about()));
    addAction(a);
    a = new QAction(tr("About Qt"), this);
    connect(a, SIGNAL(triggered()), parent, SLOT(menu_about_qt()));
    addAction(a);
    addSeparator();
    a = new QAction(tr("Quit"), this);
    addAction(a);
    connect(a, SIGNAL(triggered()), parent, SIGNAL(menu_quit()));
    connect(this, SIGNAL(set_color(int)), parent, SLOT(menu_color(int)));
}

bool
PopupMenu::is_window_locked()
{
    return lock_pos->isChecked();
}

void
PopupMenu::set_window_lock(bool s)
{
    lock_pos->setChecked(s);
}

bool
PopupMenu::is_window_ontop()
{
    return window_ontop->isChecked();
}

void
PopupMenu::set_window_ontop(bool s)
{
    window_ontop->setChecked(s);
}

/*
 * SLOTS
 */

void PopupMenu::color_0()
{
    emit set_color(0);
}

void PopupMenu::color_1()
{
    emit set_color(1);
}
