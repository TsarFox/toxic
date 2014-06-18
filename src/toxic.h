/*  toxic.h
 *
 *
 *  Copyright (C) 2014 Toxic All Rights Reserved.
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

#ifndef _toxic_h
#define _toxic_h

#ifndef TOXICVER
#define TOXICVER "NOVER_"    /* Use the -D flag to set this */
#endif

#include <stdbool.h>
#include <curses.h>

#include <tox/tox.h>

#define UNKNOWN_NAME "Anonymous"

#define MAX_FRIENDS_NUM 500
#define MAX_STR_SIZE 256
#define MAX_CMDNAME_SIZE 64
#define TOXIC_MAX_NAME_LENGTH 32   /* Must be <= TOX_MAX_NAME_LENGTH */
#define KEY_IDENT_DIGITS 2    /* number of hex digits to display for the pub-key based identifier */
#define TIME_STR_SIZE 16

#define EXIT_SUCCESS 0

/* ASCII key codes */
#define T_KEY_KILL       0x0B     /* ctrl-k */
#define T_KEY_DISCARD    0x15     /* ctrl-u */
#define T_KEY_NEXT       0x10     /* ctrl-p */
#define T_KEY_PREV       0x0F     /* ctrl-o */
#define T_KEY_C_E        0x05     /* ctrl-e */
#define T_KEY_C_A        0x01     /* ctrl-a */
#define T_KEY_ESC        0x1B     /* ESC key */
#define T_KEY_C_RB       0x1D     /* ctrl-] */
#define T_KEY_C_LB       0x1B     /* ctrl-[ */

enum {
    MOVE_UP,
    MOVE_DOWN,
} KEY_DIRS;

typedef enum _FATAL_ERRS {
    FATALERR_MEMORY = -1,
    FATALERR_FREAD = -2,
    FATALERR_THREAD_CREATE = -3,
    FATALERR_MUTEX_INIT = -4,
    FATALERR_LOCALE_SET = -5,
    FATALERR_STORE_DATA = -6,
    FATALERR_NETWORKINIT = -7,
    FATALERR_INFLOOP = -8,
    FATALERR_WININIT = -9,
} FATAL_ERRS;

/* Fixes text color problem on some terminals.
   Uncomment if necessary */
/* #define URXVT_FIX */

void exit_toxic_success(Tox *m);
void exit_toxic_err(const char *errmsg, int retcode);

void on_request(Tox *m, const uint8_t *public_key, const uint8_t *data, uint16_t length, void *userdata);
void on_connectionchange(Tox *m, int32_t friendnumber, uint8_t status, void *userdata);
void on_message(Tox *m, int32_t friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_action(Tox *m, int32_t friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_nickchange(Tox *m, int32_t friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_statuschange(Tox *m, int32_t friendnumber, uint8_t status, void *userdata);
void on_statusmessagechange(Tox *m, int32_t friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_friendadded(Tox *m, int32_t friendnumber, bool sort);
void on_groupmessage(Tox *m, int groupnumber, int peernumber, uint8_t *message, uint16_t length, void *userdata);
void on_groupaction(Tox *m, int groupnumber, int peernumber, uint8_t *action, uint16_t length, void *userdata);
void on_groupinvite(Tox *m, int32_t friendnumber, uint8_t *group_pub_key, void *userdata);
void on_group_namelistchange(Tox *m, int groupnumber, int peernumber, uint8_t change, void *userdata);
void on_file_sendrequest(Tox *m, int32_t friendnumber, uint8_t filenumber, uint64_t filesize, uint8_t *pathname,
                         uint16_t pathname_length, void *userdata);
void on_file_control(Tox *m, int32_t friendnumber, uint8_t receive_send, uint8_t filenumber, uint8_t control_type,
                     uint8_t *data, uint16_t length, void *userdata);
void on_file_data(Tox *m, int32_t friendnumber, uint8_t filenumber, uint8_t *data, uint16_t length, void *userdata);
void on_typing_change(Tox *m, int32_t friendnumber, uint8_t is_typing, void *userdata);

#endif  /* #define _toxic_h */