#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Ui_MainWindow *ui = this->ui;
    QToolButton *b1 = new QToolButton;

    QSignalMapper *signalMapper = new QSignalMapper(this);

    // Important : all of signalMapper code must below on ui->setupUi
    ui->setupUi(this);


    // mapped
    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(iInsert(int)));
    //H1 to iInsert
    connect(ui->iH1, SIGNAL(clicked()),
           signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->iH1, int(1));


    // editor to convert
    connect(ui->editor, &QTextBrowser::textChanged,
            this, &MainWindow::convert);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::iInsert(int i)
{
    qDebug("iinsert");
    return 0;
}

// Slot of MainWindow
// For handle convert markdown to html
// Single receive from editor, when it text change
int MainWindow::convert()
{
    Ui_MainWindow *ui = this->ui;
    //

    // reload markdown
    //ui->markdown_viewer->setText("change word");
    ui->markdown_viewer->reload();

    return 0;
}
