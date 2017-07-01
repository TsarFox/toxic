/*  api.h
 *
 *
 *  Copyright (C) 2017 Jakob Kreuze <jakob@memeware.net>
 *
 *  This file is part of Toxic.
 *
 *  Toxic is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Toxic is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Toxic.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef API_H
#define API_H

#include "friendlist.h"
#include "line_info.h"
#include "windows.h"

void api_display(const char *const msg);
FriendsList api_get_friendslist(void);
char *api_get_nick(void);
TOX_USER_STATUS api_get_status(void);
char *api_get_status_message(void);
void api_send(const char *msg);
struct history *api_get_history(void);
void api_execute(const char *input, int mode);
int do_plugin_command(int num_args, char (*args)[MAX_STR_SIZE]);
void do_message_callbacks(const char *msg);
int num_registered_handlers(void);
int help_max_width(void);
void draw_handler_help(WINDOW *win);
void invoke_autoruns(WINDOW *w, ToxWindow *self);

#endif /* #define API_H */
