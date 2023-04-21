#include "include/mainwindow.h"
#include "include/ui_header/ui_mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    m_oCliptool = new CClipTool(this);
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

