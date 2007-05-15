/* 
 *  Matchbox Keyboard - A lightweight software keyboard.
 *
 *  Authored By Matthew Allum <mallum@o-hand.com>
 *
 *  Copyright (c) 2007 OpenedHand Ltd - http://o-hand.com
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

#include "matchbox-keyboard.h"

static Atom Atom_MB_IM_INVOKER_COMMAND;

void
mb_kbd_remote_init (MBKeyboardUI *ui)
{
  Atom_MB_IM_INVOKER_COMMAND = XInternAtom(mb_kbd_ui_x_display(ui), 
					   "_MB_IM_INVOKER_COMMAND", False);
}

void
mb_kbd_remote_process_xevents (MBKeyboardUI *ui, XEvent *xevent)
{
  DBG("got a message\n");

  switch (xevent->type)
    {
    case ClientMessage:
      DBG("is a Client Message\n");
      if (xevent->xclient.message_type == Atom_MB_IM_INVOKER_COMMAND)
	{
	  DBG("got a message of type _MB_IM_INVOKER_COMMAND, val %i\n",
	      xevent->xclient.data.l[0]);
	  if (xevent->xclient.data.l[0] == 1)
	      mb_kbd_ui_show (ui);
	  else
	      mb_kbd_ui_hide (ui);
	}
    }
}