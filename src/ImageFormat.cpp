#include "ImageFormat.h"

#include <QFile>
#include <QFileDialog>
#include <QDialog>

ImageFormat::ImageFormat(QWidget* parent)
    :QWidget(parent)
{

}

bool ImageFormat::save(const std::string& filename)
{
    return true;
}

bool ImageFormat::create()
{

    return false;
}
bool ImageFormat::read(std::string& filename)
{
    
    return true;
}
