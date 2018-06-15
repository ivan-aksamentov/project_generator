#pragma once

#include <memory>

#include <QMainWindow>

class Ui_MainWindow;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);

 private:
  std::shared_ptr<Ui_MainWindow> ui;
};
