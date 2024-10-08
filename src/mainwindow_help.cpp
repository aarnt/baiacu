/*
* This file is part of Baiacu, an open-source GUI for OpenBSD pkg.
* Copyright (C) 2024 Alexandre Albuquerque Arnt
*               2013  Manuel Tortosa
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

/*
 * This is MainWindow's Help related code
 */

#include "strconstants.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbar.h"

#include <QString>
#include <QTextBrowser>
#include <QMessageBox>
#include <QDesktopServices>

/*
 * Initialize the Help tab with basic information about using OctoPkg
 */
void MainWindow::initTabHelpUsage()
{
  QWidget *tabHelpUsage = new QWidget();
  QGridLayout *gridLayoutX = new QGridLayout(tabHelpUsage);
  gridLayoutX->setSpacing(0);
  gridLayoutX->setContentsMargins(0, 0, 0, 0);

  QTextBrowser *text = new QTextBrowser(tabHelpUsage);
  text->setObjectName("textBrowser");
  text->setReadOnly(true);
  text->setFrameShape(QFrame::NoFrame);
  text->setFrameShadow(QFrame::Plain);
  text->setOpenExternalLinks(true);
  gridLayoutX->addWidget(text, 0, 0, 1, 1);

  QString iconPath = "<img height=\"16\" width=\"16\" src=\":/resources/images/";

  QString strForMoreInfo = tr("For more information, visit:");
  QString html =
    QString("<h2>Baiacu</h2>") +
    QString("<h3><p>") + tr("A Qt based OpenBSD pkg front-end,") + " " +
    tr("licensed under the terms of") + " ";

  html +=
      QString("<a href=\"https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html\">LGPL v2.1</a>.</p></h3><br>"); //+
      //QString("<h4><p>") + strForMoreInfo + " " +
      //QString("<a href=\"https://tintaescura.com/projects/octopkg\">https://tintaescura.com/projects/octopkg</a>.</p></h4><br>");

  html += tr("Package classification:") +
  QString("<ul type=\"square\"><li>") + iconPath + "installed.png\"/> " +
     tr("An installed package") + QString("</li>") +
  QString("<li>") + iconPath + "unrequired.png\"/> " +
     tr("An explicitly installed package") +
  QString("</li>") +
  QString("<li>") + iconPath + "noninstalled.png\"/> " +
     tr("A non installed package") +
  QString("</li></ul>") +

     tr("Basic usage help:") +
  QString("<ul><li>") +
     tr("Position the mouse over a package to see its one line comment") +
  QString("</li><li>") +
     tr("Double click an installed package to see its contents") +
  QString("</li><li>") +
     tr("Right click package to install/reinstall or remove it") +
  QString("</li></ul>") +

     tr("Alt+key sequences:") +
  QString("<ul><li>") +
     tr("Alt+1 to switch to 'Info' tab") +
  QString("</li><li>") +
     tr("Alt+2 to switch to 'Files' tab") +
  QString("</li><li>") +
     tr("Alt+3 to switch to 'Actions' tab") +
  QString("</li><li>") +
     tr("Alt+4 to switch to 'Output' tab") +
  QString("</li><li>") +
     tr("Alt+5 to switch to 'News' tab") +
  QString("</li><li>") +
     tr("Alt+6 or 'F1' to show this help page") +
  QString("</li><li>") +
     tr("Alt+\"Left key\" to go to previous clicked anchor") +
  QString("</li><li>") +
     tr("Alt+\"Right key\" to go to next clicked anchor") +
  QString("</li><li>") +
     tr("Alt+\"Home key\" to go to first clicked anchor") +
  QString("</li><li>") +
     tr("Alt+\"End key\" to go to last clicked anchor") +
  QString("</li></ul>") +

     tr("Control+key sequences:") +
  QString("<ul><li>") +
     tr("Ctrl+K or 'File/Check updates' to search for latest package updates") +
  QString("</li><li>") +
     tr("Ctrl+U or 'File/Install updates' to install available package updates") +
  QString("</li><li>") +
     tr("Ctrl+L to find a package in the package list") +
  QString("</li><li>") +
     tr("Ctrl+I to install a new package") +
  QString("</li><li>") +
     tr("Ctrl+P to go to the package list") +
  QString("</li><li>") +
     tr("Ctrl+F to search for text inside tab Files, News and Usage") +
  QString("</li><li>") +
     tr("Ctrl+M or 'Actions/Apply' to start installation/removal of selected packages") +
  QString("</li><li>") +
     tr("Ctrl+E or 'Actions/Cancel' to clear the selection of \"to be removed\" and \"to be installed\" packages") +
  QString("</li><li>") +
     tr("Ctrl+G or 'File/Get latest BSD news' to retrieve latest RSS based OpenBSD news") +
  QString("</li><li>") +
     tr("Ctrl+Q or 'File/Exit' to exit the application") +
  QString("</li></ul>") +

  tr("Control+Shift+key sequences:") +
  QString("<ul><li>") +
     tr("Ctrl+Shift+F to fake install selected packages") +

  QString("</li></ul>") +
     tr("F+key sequences:") +
  QString("<ul><li>") +
     tr("F1 to show this help page") +
  QString("</li><li>") +
     tr("F4 to open a Terminal whitin the selected directory at Files tab") +
  QString("</li><li>") +
     tr("F6 to open a File Manager whitin the selected directory at Files tab") +
  QString("</li><li>") +
     tr("F10 to maximize/demaximize package list view") +
  QString("</li><li>") +
     tr("F11 to maximize/demaximize Tab's view") +
  QString("</li></ul><br>");

  text->setText(html);
  int tindex = ui->twProperties->addTab(tabHelpUsage, StrConstants::getHelpUsage() );
  ui->twProperties->setTabText(ui->twProperties->indexOf(tabHelpUsage), StrConstants::getHelpUsage());

  SearchBar *searchBar = new SearchBar(this);
  connect(searchBar, SIGNAL(textChanged(QString)), this, SLOT(searchBarTextChangedInTextBrowser(QString)));
  connect(searchBar, SIGNAL(closed()), this, SLOT(searchBarClosedInTextBrowser()));
  connect(searchBar, SIGNAL(findNext()), this, SLOT(searchBarFindNextInTextBrowser()));
  connect(searchBar, SIGNAL(findPrevious()), this, SLOT(searchBarFindPreviousInTextBrowser()));
  gridLayoutX->addWidget(searchBar, 1, 0, 1, 1);

  text->show();
  ui->twProperties->setCurrentIndex(tindex);
  text->setFocus();
}

/*
 * Slot to position twProperties at Help tab
 */
void MainWindow::onHelpUsage()
{
  changeTabWidgetPropertiesIndex(ctn_TABINDEX_HELPUSAGE);
}

/*
 * Slot to open author's Paypal donation page
 */
void MainWindow::onHelpDonate()
{
  const QString url="http://sourceforge.net/donate/index.php?group_id=186459";
  QDesktopServices::openUrl(QUrl(url));
}

/*
 * Slot which opens the About dialog
 */
void MainWindow::onHelpAbout()
{
  QString aboutText = "<b>" + StrConstants::getApplicationName() + QLatin1String("</b><br><br>");
  aboutText += StrConstants::getVersion() + QLatin1String(": ") + StrConstants::getApplicationVersion() +
      QLatin1String(" - ") + StrConstants::getQtVersion() + QLatin1String("<br>");
  aboutText += StrConstants::getURL() + QLatin1String(": ") +
    QStringLiteral("<a href=\"https://tintaescura.com/projects/baiacu/\">https://tintaescura.com/projects/baiacu</a><br>");
  aboutText += StrConstants::getLicenses() + QLatin1String(": ") +
      QStringLiteral("<a href=\"https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html\">LGPL v2.1</a><br><br>");
  aboutText += QStringLiteral("&copy; Alexandre Albuquerque Arnt<br><br>");

  QMessageBox::about(this, StrConstants::getHelpAbout(), aboutText);
}
