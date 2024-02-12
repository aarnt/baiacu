/*
* This file is part of OctoPkg, an open-source GUI for pkgng.
* Copyright (C) 2015 Alexandre Albuquerque Arnt
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
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*/

#ifndef MAINWINDOW_GLOBALS_H
#define MAINWINDOW_GLOBALS_H

#include "strconstants.h"
#include "model/packagemodel.h"

#include <QFutureWatcher>

typedef std::pair<QString, QStringList*> GroupMemberPair;

inline QFutureWatcher<QString> g_fwToolTip;
inline QFutureWatcher<QString> g_fwToolTipInfo;
inline QFutureWatcher<QList<PackageListData> *> g_fwPkg;
inline QFutureWatcher<QSet<QString> *> g_fwUnrequiredPacman;
inline QFutureWatcher<GroupMemberPair>          g_fwPacmanGroup;
inline QFutureWatcher<QList<PackageListData> *> g_fwRemote;
inline QFutureWatcher<QList<PackageListData> *> g_fwRemoteMeta;
inline QFutureWatcher<QMap<QString, OutdatedPackageInfo> *> g_fwOutdatedList;
inline QFutureWatcher<QString> g_fwDistroNews;
inline QFutureWatcher<QString> g_fwPackageOwnsFile;
inline QFutureWatcher<TransactionInfo> g_fwTargetUpgradeList;

QString showPackageDescription(QString pkgName);
TransactionInfo getTargetUpgradeList(const QString &pkgName);
QList<PackageListData> * searchPkgPackages();
QSet<QString> * searchUnrequiredPackages();
QList<PackageListData> * searchRemotePackages(QString searchString);
QString searchPacmanPackagesByFile(const QString &file);
GroupMemberPair          searchPacmanPackagesFromGroup(QString groupName);
QString getLatestDistroNews();

#endif // MAINWINDOW_GLOBALS_H
