/*
  objectidfilterproxymodel.h

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

#ifndef GAMMARAY_OBJECIDFILTERPROXYMODEL_H
#define GAMMARAY_OBJECIDFILTERPROXYMODEL_H

#include "gammaray_core_export.h"
#include "objectmodelbase.h"

#include <QSortFilterProxyModel>

namespace GammaRay {

/**
 * @brief A QSortFilterProxyModel for generic ObjectIds.
 */
class GAMMARAY_CORE_EXPORT ObjectIdFilterProxyModelBase : public QSortFilterProxyModel
{
  Q_OBJECT
  public:
    /**
     * Constructor.
     * @param parent is the parent object for this instance.
     */
    explicit ObjectIdFilterProxyModelBase(QObject *parent = Q_NULLPTR);

  protected:
    /**
     * Determines if the item in the specified row can be included in the model.
     * @param source_row is a non-zero integer representing the row of the item.
     * @param source_parent is the parent QModelIndex for this model.
     * @return true if the item in the row can be included in the model;
     *         otherwise returns false.
     */
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const Q_DECL_OVERRIDE;

    /**
     * Determines if the specified ObjectIDd can be included in the model.
     * @param id is a ref to the ObjectId to test.
     * @return true if the ObjectId can be included in the model; false otherwise.
     */
    virtual bool filterAcceptsObjectId(const GammaRay::ObjectId &id) const = 0;
};

/**
 * @brief A generic ObjectIdFilterProxyModelBase.
 * Filter in and sort according to the objects list.
 */
class GAMMARAY_CORE_EXPORT ObjectIdsFilterProxyModel : public ObjectIdFilterProxyModelBase
{
  public:
    /**
     * Constructor.
     * @param parent is the parent object for this instance.
     */
    explicit ObjectIdsFilterProxyModel(QObject *parent = 0);

    GammaRay::ObjectIds ids() const;
    void setIds(const GammaRay::ObjectIds &ids);

protected:
    bool filterAcceptsObjectId(const GammaRay::ObjectId &id) const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const Q_DECL_OVERRIDE;


private:
    GammaRay::ObjectIds m_ids;
    QMap<quint64, int> m_sorting; // ObjectId::id, m_ids index
};

}

#endif // GAMMARAY_OBJECIDFILTERPROXYMODEL_H
