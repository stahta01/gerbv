/*
 * gEDA - GNU Electronic Design Automation
 * This file is a part of gerbv.
 *
 *   Copyright (C) 2000-2002 Stefan Petersen (spe@stacken.kth.se)
 *
 * $Id$
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 */

#ifndef GERBV_SCREEN_H
#define GERBV_SCREEN_H

#include <gtk/gtk.h>
#include <gdk/gdk.h>

#define INITIAL_SCALE 200
#define MAX_FILES 20

typedef enum {NORMAL, MOVE, ZOOM_OUTLINE} gerbv_state_t;

typedef struct {
    gerb_image_t *image;
    GdkColor *color;
} gerbv_fileinfo_t;


typedef struct {
    GtkWidget *drawing_area;
    GdkPixmap *pixmap;
    GdkColor  *background;
    GdkColor  *err_color;
    GdkColor  *zoom_outline_color;
    
    GtkWidget *load_file_popup;
    GtkWidget *color_selection_popup;

    gerbv_fileinfo_t *file[MAX_FILES];
    int curr_index;
    char *path;

    GtkTooltips *tooltips;
    GtkWidget *layer_button[MAX_FILES];
    GtkWidget *popup_menu;

    gerbv_state_t state;

    int scale;

    gint last_x;
    gint last_y;
    gint zstart_x;		/* Zoom box start coordinates */
    gint zstart_y;

    int trans_x; /* Translate offset */
    int trans_y;
} gerbv_screen_t;

extern gerbv_screen_t screen;

#endif /* GERBV_SCREEN_H */