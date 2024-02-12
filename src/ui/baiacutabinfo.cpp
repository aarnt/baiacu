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

#include "baiacutabinfo.h"
#include "src/strconstants.h"
#include "src/package.h"

#include <QDebug>
#include <QHash>
#include <QRegularExpression>

/*
 * The OctopiTabInfo class provides functionality for the Tab "Info"
 */

/**
 * @brief OctopiTabInfo::anchorBegin for navigation
 */
const QString BaiacuTabInfo::anchorBegin("anchorBegin");

BaiacuTabInfo::BaiacuTabInfo()
{
}

/**
 * This function has been extracted from src/mainwindow_refresh.cpp void MainWindow::refreshTabInfo(QString pkgName)
 */
QString BaiacuTabInfo::formatTabInfo(const PackageRepository::PackageData& package,
                                     const QMap<QString, OutdatedPackageInfo>& outdatedPkgList)
{
  Q_UNUSED(outdatedPkgList)

  PackageInfoData pid = Package::getInformation(package.name);

  QString version = StrConstants::getVersion();
  QString url = StrConstants::getURL();
  QString maintainer = StrConstants::getMaintainer();
  QString comment = StrConstants::getComment();
  QString description = StrConstants::getDescription();

  //Let's put package description in UTF-8 format  
  QString pkgDescription;

  QString html;
  html += "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">";
  html += "<a id=\"" + anchorBegin + "\"></a>";
  html += "<h2>" + package.name + "</h2>";
  html += pkgDescription;
  html += "<table border=\"0\">";
  html += "<tr><th width=\"20%\"></th><th width=\"80%\"></th></tr>";

  if (!pid.url.isEmpty())
    html += "<tr><td>" + url + "</td><td>" + pid.url + "</td></tr><tr><td></tr></td>";

  html += "<tr><td>" + version + "</td><td>" + package.version + "</td></tr><tr><td></tr></td>";

  //This is needed as packager names could be encoded in different charsets, resulting in an error
  QString packagerName = pid.maintainer;
  packagerName = packagerName.replace("<", "&lt;");
  packagerName = packagerName.replace(">", "&gt;");

  html += "<tr><td>" + comment + "</td><td>" + pid.comment + "</td></tr><tr><td></tr></td>";

  html += "<tr><td>" + description + "</td><td>" + pid.description + "</td></tr><tr><td></tr></td>";

  if (!packagerName.isEmpty())
    html += "<tr><td>" + maintainer + "</td><td>" + packagerName + "</td></tr><tr><td></tr></td>";

  html += "</table><br>";

  return html;
}
