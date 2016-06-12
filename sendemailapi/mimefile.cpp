#include "mimefile.h"
#include <QFileInfo>

MimeFile::MimeFile(QFile *file)
{
    this->file = file;
    this->cType = "application/octet-stream";//任意的二进制文件传输
    this->cName = QFileInfo(*file).fileName();
    this->cEncoding = _8Bit;
}

MimeFile::~MimeFile()
{
    delete file;
}

void MimeFile::prepare()
{
    file->open(QIODevice::ReadOnly);//QIODevice:输入输出设备的基类
    this->content = file->readAll();
    file->close();    
    MimePart::prepare();
}
