#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

const QString ctn_PKG_BIN = QStringLiteral("/usr/sbin/pkg");
const QString ctn_PKG_ADD_BIN = QStringLiteral("/usr/sbin/pkg_add");
const QString ctn_PKG_DELETE_BIN = QStringLiteral("/usr/sbin/pkg_delete");
const QString ctn_PKG_INFO = QStringLiteral("/usr/sbin/pkg_info");
const QString ctn_BAIACU_DOAS = QStringLiteral("/usr/local/lib/baiacu/baiacu-doas");
const QString ctn_BAIACU_DOAS_PARAMS = QStringLiteral("-d");

#endif // CONSTANTS_H
