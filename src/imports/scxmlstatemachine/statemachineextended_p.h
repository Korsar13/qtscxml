/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtScxml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef STATEMACHINEEXTENDED_P_H
#define STATEMACHINEEXTENDED_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtScxml/qscxmlglobals.h>
#include <QtScxml/qscxmlstatemachine.h>
#include <QtCore/qobject.h>
#include <QtQml/qqmllist.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

/* Allow State Machines created from QML to have children. */
class QScxmlStateMachineExtended : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> children READ children)
    Q_CLASSINFO("DefaultProperty", "children")
public:
    QScxmlStateMachineExtended(QObject *extendee);
    QQmlListProperty<QObject> children();

private:
    QObjectList m_children;
};

// The QScxmlStateMachine is defined in the scxml library
struct QScxmlStateMachineForeign
{
    Q_GADGET
    QML_UNCREATABLE("Only created through derived types")
    QML_NAMED_ELEMENT(StateMachine)
    QML_FOREIGN(QScxmlStateMachine)
    QML_EXTENDED(QScxmlStateMachineExtended)
    QML_ADDED_IN_VERSION(5,8)
};

QT_END_NAMESPACE

#endif // STATEMACHINEEXTENDED_P_H
