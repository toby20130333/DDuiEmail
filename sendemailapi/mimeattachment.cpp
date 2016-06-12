#include "mimeattachment.h"
#include <QFileInfo>

MimeAttachment::MimeAttachment(QFile *file)
    : MimeFile(file)
{
}

MimeAttachment::~MimeAttachment()
{
}

void MimeAttachment::prepare()
{
    this->header += "Content-disposition: attachment\r\n"; //当用户想把请求所得的内容存为一个文件的时候提供一个默认的文件名
    MimeFile::prepare();
}
