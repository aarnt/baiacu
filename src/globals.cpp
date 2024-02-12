/*
* This file is part of Baiacu, an open-source GUI for OpenBSD pkg.
* Copyright (C) 2024 Alexandre Albuquerque Arnt
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

#include "globals.h"
#include "mainwindow.h"

#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrentMap>

/*
 * Given a packageName, returns its description
 */
QString showPackageDescription(QString pkgName)
{
  MainWindow *mw = MainWindow::returnMainWindow();
  const PackageRepository::PackageData*const package = mw->getFirstPackageFromRepo(pkgName);

  if (package == NULL) {
    return "";
  }

  //QString description = package->comment.trimmed();

  QStringList sl;
  sl << "-c";
  sl << package->name;

  QString description = Package::getComment(UnixCommand::performQuery(sl));

  if (description.isEmpty())
  {
    return "";
  }

  //int space = description.indexOf(" ");
  //QString desc = description.mid(space+1).trimmed();
  QString desc = description.trimmed();
  int size = desc.size();

  if (desc.size() > 120)
  {
    desc.chop(size - 120);
    desc = desc + " ...";
  }

  return desc;
}

/*
 * Starts the non blocking search for OpenBSD packages...
 */
QList<PackageListData> * searchPkgPackages()
{
  return Package::getPackageList("");
}

/*
 * Starts the non blocking search for Unrequired OpenBSD packages...
 */
QSet<QString> *searchUnrequiredPackages()
{
  return Package::getUnrequiredPackageList();
}

/*
 * Starts the non blocking search for a OpenBSD package that owns the given file...
 */
QString searchPacmanPackagesByFile(const QString &file)
{
  QString result;

  if (!file.isEmpty())
  {
    result = UnixCommand::getPackageByFilePath(file);
  }
  else
    result = "";

  return result;
}

/*
 * Starts the non blocking search for Pacman packages...
 */
GroupMemberPair searchPacmanPackagesFromGroup(QString groupName)
{
  return std::make_pair(groupName, Package::getPackagesOfGroup(groupName));
}

/*
 * Starts the non blocking search for AUR packages...
 */
QList<PackageListData> * searchRemotePackages(QString searchString)
{
  return Package::getRemotePackageList(searchString);
}

/*
 * Starts the non blocking search for RSS distro news...
 */
QString getLatestDistroNews()
{
  return utils::retrieveDistroNews(true);
}

/*
 * Starts the non blocking 'pkg upgrade -n'
 */
TransactionInfo getTargetUpgradeList(const QString& pkgName)
{
  return Package::getTargetUpgradeList(pkgName);
}
