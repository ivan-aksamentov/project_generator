#include <QLabel>
#include <QWidget>

#include "main_window.h"
#include "ui_main_window.h"

#include <plchldr/plchldr.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(std::make_shared<Ui_MainWindow>()) {
  ui->setupUi(this);

  setWindowTitle(APP_NAME);

  const auto label = new QLabel(ui->centralWidget);
  label->setText(QString("Hello, this is %1\n"
                         "Today is %2\n"
                         "Here is some int: %3\n")
                     .arg(APP_NAME)
                     .arg(QString::fromStdString(day_of_week_today()))
                     .arg(QString::number(add(2, 3))));
}
