#ifndef XMLRPC_GUI_COMM_HPP
#define XMLRPC_GUI_COMM_HPP

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <vector>
#include <QDirIterator>
#include <QThread>

#include "env_vars.hpp"
#include "gui_utility_functions.hpp"

class xmlrpc_gui_comm {
public:
  xmlrpc_gui_comm();
  QString getDAQInterfaceStatus();
  void listDAQInterfaceComponents();
  void setDAQInterfaceComponents(const QStringList& components);
  void sendTransitionBOOT(const QStringList& selected_boot_file);
  void sendTransitionCONFIG(const QStringList& selected_config);
  void sendTransitionSTOP();
  void sendTransitionTERMINATE();
  void sendTransitionSTART();
  void listDAQInterfaceConfigs();
  void setShellScripts(bool value);
private:
  QString serverUrl = "http://localhost:5570/RPC2";
  // QString methodName = "listdaqcomps";
  xmlrpc_c::clientSimple guiClient;
  bool shellScriptsEnabled = false;
};

#endif // XMLRPC_GUI_COMM_HPP
