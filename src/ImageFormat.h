#pragma once

#include "MainPanel.h"
#include <QWidget>
#include <QColor>
#include <string>
#include <vector>

class ImageFormat : QWidget 
{
    Q_OBJECT

    public:
        ImageFormat(QWidget* parent = nullptr);

        bool save(const std::string& filename);
        bool create();
        bool read(std::string& filename);
    
    signals:
        void newPanelCreated(const QString& filenName, MainPanel* panel);

    private:
        size_t width;
        size_t height;

        QColor m_backgroundColor;

        std::vector<unsigned char> pixels;

        void createFile(const std::string& filename, const size_t& w, const size_t& h, const std::vector<unsigned char>& p);
};
