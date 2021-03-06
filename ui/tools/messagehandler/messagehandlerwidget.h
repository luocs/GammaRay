/*
  messagehandlerwidget.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Milian Wolff <milian.wolff@kdab.com>

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
#ifndef GAMMARAY_MESSAGEHANDLERWIDGET_H
#define GAMMARAY_MESSAGEHANDLERWIDGET_H

#include <ui/uistatemanager.h>

#include <QWidget>

QT_BEGIN_NAMESPACE
class QItemSelection;
class QStringListModel;
class QTime;
QT_END_NAMESPACE

namespace GammaRay {

namespace Ui {
  class MessageHandlerWidget;
}

class MessageHandlerWidget : public QWidget
{
  Q_OBJECT
  public:
    explicit MessageHandlerWidget(QWidget *parent = 0);
    ~MessageHandlerWidget();

  private slots:
    void fatalMessageReceived(const QString &app, const QString &message,
                              const QTime &time, const QStringList &backtrace);
    void copyToClipboard(const QString &message);
    void messageContextMenu(const QPoint &pos);
    void messageSelected(const QItemSelection &selection);

  private:
    QScopedPointer<Ui::MessageHandlerWidget> ui;
    UIStateManager m_stateManager;
    QStringListModel *m_backtraceModel;
};

}

#endif // MESSAGEHANDLERWIDGET_H
