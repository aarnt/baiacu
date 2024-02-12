/*
* This file is part of OctoPkg, an open-source GUI for pkgng.
* Copyright (C) 2014 Thomas Binkau
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

#ifndef BAIACUTABINFO_H
#define BAIACUTABINFO_H

#include "src/packagerepository.h"
#include "src/package.h"

/*
 * The BaiacuTabInfo class provides functionality for the Tab "Info"
 */

class BaiacuTabInfo
{
public:
  BaiacuTabInfo();
  
  /**
   * @brief formats TabInfo as HTML
   * @param package (the package to show details for)
   * @param outdatedAURPackagesNameVersion
   * @return html
   *
   * This function has been extracted from src/mainwindow_refresh.cpp void MainWindow::refreshTabInfo(QString pkgName)
   */
  static QString formatTabInfo(const PackageRepository::PackageData& package, const QMap<QString, OutdatedPackageInfo> &outdatedRemotePackagesNameVersion);

  static const QString anchorBegin;
};

#endif // BAIACUTABINFO_H
