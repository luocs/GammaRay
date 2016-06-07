/*
  probecontrollerclient.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2013-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
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

#ifndef GAMMARAY_PROBECONTROLLERCLIENT_H
#define GAMMARAY_PROBECONTROLLERCLIENT_H

#include <common/probecontrollerinterface.h>

namespace GammaRay {

class ProbeControllerClient : public ProbeControllerInterface
{
  Q_OBJECT
  Q_INTERFACES(GammaRay::ProbeControllerInterface)
public:
  explicit ProbeControllerClient(QObject *parent = 0);

  void selectObject(ObjectId id, const QString &toolId) Q_DECL_OVERRIDE;
  void requestSupportedTools(ObjectId id) Q_DECL_OVERRIDE;
  void requestEnabledTools() Q_DECL_OVERRIDE;
  void selectTool(const QString &toolId) Q_DECL_OVERRIDE;

  void detachProbe() Q_DECL_OVERRIDE;
  void quitHost() Q_DECL_OVERRIDE;
};

}

#endif // GAMMARAY_PROBECONTROLLERCLIENT_H
