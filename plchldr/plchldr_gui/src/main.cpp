#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "main_window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  app.setApplicationName(APP_NAME);

  QFile styleSheetFile(":qdarkstyle/style.qss");
  if (styleSheetFile.exists()) {
    styleSheetFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream styleSheetText(&styleSheetFile);
    app.setStyleSheet(styleSheetText.readAll());
  }

  MainWindow w;
  w.show();

  return app.exec();
}
