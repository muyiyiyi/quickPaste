#ifndef CCLIPTOOL_H
#define CCLIPTOOL_H
#include <QClipboard>
#include <QObject>
#include <QMimeData>

class CClipTool : public QObject
{
    Q_OBJECT
public:
    /*explicit*/ CClipTool(QObject *parent = nullptr, bool isOnlyText=true);
    ~CClipTool();

    bool save_content(QMimeData* mime_data, QString save_path);

public slots:
    void slot_clipboard_changed();  // 剪切板的内容变化了，通常是新增了

private:
    /*static*/ QClipboard *m_clipboard; // 剪切板对象
    bool m_bOnlyPlainText; // 是否只保存为纯文本。 区分html，比如从编辑器，office复制的文本，有格式不是纯文本
    bool m_bAutoCopyfile;  // 如果剪切板的内容是一个路径，文件或目录，是否自动转为复制文件和目录
    QList<QMimeData*> *m_qlist_clipboard_history;

    bool save_text(QString content, QString filepath);

signals:

};

#endif // CCLIPTOOL_H
