#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QDebug>
#include <QString>
#include <QToolButton>
#include <QProcess>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QIODevice>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



public slots:
    int convert();
    int iInsert(int i);

private:
    Ui::MainWindow *ui;
    QByteArray md_data;
    QFile md_file;

};

enum {
    H1,H2,H3,H4,H5,H6,
    TITLE,
    CODE,
    CODE_BLOCK,IMG,LINK
};
#endif // MAINWINDOW_H
