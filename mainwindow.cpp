#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->editor->setText("cba");

    connect(ui->editor, &QTextBrowser::textChanged,
            this, &MainWindow::convert);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::iInsert()
{

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
