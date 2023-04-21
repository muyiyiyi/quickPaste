#include "include/cliptool.h"
#include <QGuiApplication>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
//QClipboard *CClipTool::clipboard = QGuiApplication::clipboard();


CClipTool::CClipTool(QObject *parent, bool isOnlyText) : QObject(parent), m_bOnlyPlainText(isOnlyText)
{
    m_clipboard = QGuiApplication::clipboard();
    m_qlist_clipboard_history = new QList<QMimeData*>;
    connect(m_clipboard, SIGNAL(dataChanged()),this, SLOT(slot_clipboard_changed()));
}


/* 剪切板的内容发生了变化*/
void CClipTool::slot_clipboard_changed()
{
    const QMimeData *mimeData = m_clipboard->mimeData();
    qDebug() << "[INFO]剪切板新增了内容";
    m_qlist_clipboard_history->append(const_cast<QMimeData*>(mimeData) );
    save_content(const_cast<QMimeData*>(mimeData), "...");
}


bool CClipTool::save_content(QMimeData* mime_data, QString save_path)
{

    QString str_content;
    bool ret = false;
    if(mime_data->hasHtml())
    {
        qDebug() << "html可以转文本" << mime_data->html();
        str_content = m_bOnlyPlainText ? mime_data->text(): mime_data->html();
        ret = save_text(str_content, save_path);
    }
    else if (mime_data->hasText())
    {
        qDebug() << "文本" << mime_data->text();
        str_content = mime_data->text();
        ret = save_text(str_content, save_path);
    }
    else if (mime_data->hasImage())
    {
        qDebug() << "图片" << mime_data->text();
    }
    else if (mime_data->hasUrls())
    {
        qDebug() << "urls" << mime_data->text();
    }


    return ret;
}

bool CClipTool::save_text(QString content, QString filepath)
{
    if (m_bAutoCopyfile && content.startsWith("/"))
    {
        QFileInfo tmpfile(content);
        if (tmpfile.exists())
        {

        }
    }


}


CClipTool::~CClipTool()
{

}
