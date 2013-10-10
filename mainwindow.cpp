#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Ui_MainWindow *ui = this->ui;

    QSignalMapper *signalMapper = new QSignalMapper(this);

    // Important : all of signalMapper code must below on ui->setupUi
    ui->setupUi(this);


    // mapped
    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(iInsert(int)));
    //
    connect(ui->iH1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iH2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iH3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iH4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iH5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iH6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iTitle, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iCode ,SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iCodeBlock, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iImage ,SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->iLink, SIGNAL(clicked()), signalMapper, SLOT(map()));


    //
    signalMapper->setMapping(ui->iH1, H1);
    signalMapper->setMapping(ui->iH2, H2);
    signalMapper->setMapping(ui->iH3, H3);
    signalMapper->setMapping(ui->iH4, H4);
    signalMapper->setMapping(ui->iH5, H5);
    signalMapper->setMapping(ui->iH6, H6);
    signalMapper->setMapping(ui->iTitle, TITLE);
    signalMapper->setMapping(ui->iCode, CODE);
    signalMapper->setMapping(ui->iCodeBlock, CODE_BLOCK);
    signalMapper->setMapping(ui->iImage, IMG);
    signalMapper->setMapping(ui->iLink, LINK);

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
    printf("%d",i);
    Ui_MainWindow *ui = this->ui;

    switch (i) {
    case H1:
        ui->editor->insertPlainText("# ");
        break;
    case H2:
         ui->editor->insertPlainText("## ");
        break;
    case H3:
         ui->editor->insertPlainText("### ");
        break;
    case H4:
         ui->editor->insertPlainText("#### ");
        break;
    case H5:
         ui->editor->insertPlainText("##### ");
        break;
    case H6:
        ui->editor->insertPlainText("##### ");
       break;
    case TITLE:
        ui->editor->insertPlainText("TITLE\n==================\r");
       break;
    case CODE:
        ui->editor->insertPlainText("` CODE `\n");
       break;
    case CODE_BLOCK:
        ui->editor->insertPlainText("    CODE BLOCK");
       break;
    case IMG:
        ui->editor->insertPlainText("[id]: url/to/image  \"Optional title attribute\"");
       break;
    case LINK:
        ui->editor->insertPlainText("[id]: http://example.com/  \"Optional Title Here\"");
       break;
    default:
        break;
    }

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
    ui->markdown_viewer->setText(ui->editor->toPlainText());

    //ui->markdown_viewer->reload();

    return 0;
}
