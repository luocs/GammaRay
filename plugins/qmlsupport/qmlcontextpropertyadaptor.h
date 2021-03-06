/*
  qmlcontextpropertyadaptor.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

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

#ifndef GAMMARAY_QMLCONTEXTPROPERTYADAPTOR_H
#define GAMMARAY_QMLCONTEXTPROPERTYADAPTOR_H

#include <core/propertyadaptor.h>
#include <core/propertyadaptorfactory.h>

#include <QVector>

namespace GammaRay {

class QmlContextPropertyAdaptor : public PropertyAdaptor
{
    Q_OBJECT
public:
    explicit QmlContextPropertyAdaptor(QObject *parent = Q_NULLPTR);
    ~QmlContextPropertyAdaptor();

    int count() const Q_DECL_OVERRIDE;
    PropertyData propertyData(int index) const Q_DECL_OVERRIDE;
    void writeProperty(int index, const QVariant& value) Q_DECL_OVERRIDE;

protected:
    void doSetObject(const ObjectInstance &oi) Q_DECL_OVERRIDE;

private:
    QVector<QString> m_contextPropertyNames;
};

class QmlContextPropertyAdaptorFactory : public AbstractPropertyAdaptorFactory
{
public:
    PropertyAdaptor* create(const ObjectInstance& oi, QObject* parent = 0) const Q_DECL_OVERRIDE;
    static QmlContextPropertyAdaptorFactory* instance();
private:
    static QmlContextPropertyAdaptorFactory *s_instance;
};

}

#endif
