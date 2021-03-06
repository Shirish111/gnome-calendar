/* gcal-range-tree.h
 *
 * Copyright (C) 2016 Georges Basile Stavracas Neto <georges.stavracas@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GCAL_RANGE_TREE_H
#define GCAL_RANGE_TREE_H

#include <glib-object.h>

G_BEGIN_DECLS

#define GCAL_TYPE_RANGE_TREE (gcal_range_tree_get_type())

typedef struct _GcalRangeTree GcalRangeTree;

typedef gboolean    (*GcalRangeTraverseFunc)                     (guint16             start,
                                                                  guint16             end,
                                                                  gpointer            data,
                                                                  gpointer            user_data);

GType                gcal_range_tree_get_type                    (void) G_GNUC_CONST;

GcalRangeTree*       gcal_range_tree_new                         (void);

GcalRangeTree*       gcal_range_tree_copy                        (GcalRangeTree      *self);

GcalRangeTree*       gcal_range_tree_ref                         (GcalRangeTree      *self);

void                 gcal_range_tree_unref                       (GcalRangeTree      *self);

void                 gcal_range_tree_add_range                   (GcalRangeTree      *self,
                                                                  guint16             start,
                                                                  guint16             end,
                                                                  gpointer            data);

void                 gcal_range_tree_remove_range                (GcalRangeTree      *self,
                                                                  guint16             start,
                                                                  guint16             end,
                                                                  gpointer            data);

void                 gcal_range_tree_traverse                    (GcalRangeTree      *self,
                                                                  GTraverseType       type,
                                                                  GcalRangeTraverseFunc func,
                                                                  gpointer           user_data);

GPtrArray*           gcal_range_tree_get_data_at_range           (GcalRangeTree      *self,
                                                                  guint16             start,
                                                                  guint16             end);

guint64              gcal_range_tree_count_entries_at_range      (GcalRangeTree      *self,
                                                                  guint16             start,
                                                                  guint16             end);

G_DEFINE_AUTOPTR_CLEANUP_FUNC (GcalRangeTree, gcal_range_tree_unref)

G_END_DECLS

#endif /* GCAL_RANGE_TREE_H */
