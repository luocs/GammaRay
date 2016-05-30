/*
  objectidfilterproxymodel.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Filipe Azevedo <filipe.azevedo@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "objectidfilterproxymodel.h"

using namespace GammaRay;

ObjectIdFilterProxyModelBase::ObjectIdFilterProxyModelBase(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    setDynamicSortFilter(true);
}

bool ObjectIdFilterProxyModelBase::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    const QModelIndex source_index = sourceModel()->index(source_row, 0, source_parent);
    if (!source_index.isValid()) {
        return false;
    }

    const GammaRay::ObjectId id = source_index.data(ObjectModel::ObjectIdRole).value<GammaRay::ObjectId>();
    if (id.isNull() || !filterAcceptsObjectId(id)) {
        return false;
    }

    return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
}

ObjectIdsFilterProxyModel::ObjectIdsFilterProxyModel(QObject *parent)
    : ObjectIdFilterProxyModelBase(parent)
{
}

GammaRay::ObjectIds ObjectIdsFilterProxyModel::ids() const
{
    return m_ids;
}

void ObjectIdsFilterProxyModel::setIds(const GammaRay::ObjectIds &ids)
{
    if (m_ids == ids)
        return;

    m_ids = ids;
    m_sorting.clear();
    for (int i = 0; i < m_ids.count(); ++i) {
        const ObjectId &id(m_ids[i]);
        m_sorting[id.id()] = i;
    }
    invalidateFilter();
}

bool ObjectIdsFilterProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    const GammaRay::ObjectId leftId = source_left.data(ObjectModel::ObjectIdRole).value<GammaRay::ObjectId>();
    const GammaRay::ObjectId rightId = source_right.data(ObjectModel::ObjectIdRole).value<GammaRay::ObjectId>();
    return m_sorting.value(leftId.id()) < m_sorting.value(rightId.id());
}

bool ObjectIdsFilterProxyModel::filterAcceptsObjectId(const GammaRay::ObjectId &id) const
{
    return m_ids.contains(id);
}
