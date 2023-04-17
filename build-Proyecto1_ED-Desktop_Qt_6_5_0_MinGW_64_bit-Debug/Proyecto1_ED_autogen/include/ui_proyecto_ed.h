/********************************************************************************
** Form generated from reading UI file 'proyecto_ed.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROYECTO_ED_H
#define UI_PROYECTO_ED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Proyecto_ED
{
public:
    QWidget *centralwidget;
    QFrame *FramePrincipal;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *LabelImagen12;
    QLabel *LabelImagen2;
    QLabel *LabelImagen4;
    QLabel *LabelImagen3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *LabelImagen6;
    QLabel *LabelImagen8;
    QLabel *LabelImagen7;
    QLabel *LabelImagen10;
    QLabel *LabelImagen9;
    QLabel *LabelImagen5;
    QLabel *LabelImagen11;
    QLabel *LabelImagen13;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_8;
    QFrame *line_7;
    QFrame *line_9;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QFrame *line_22;
    QFrame *line_23;
    QFrame *line_24;
    QFrame *line_25;
    QFrame *line_26;
    QFrame *line_27;
    QFrame *line_28;
    QFrame *line_29;
    QFrame *line_30;
    QFrame *line_31;
    QFrame *line_32;
    QFrame *line_33;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Proyecto_ED)
    {
        if (Proyecto_ED->objectName().isEmpty())
            Proyecto_ED->setObjectName("Proyecto_ED");
        Proyecto_ED->resize(800, 600);
        Proyecto_ED->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 195, 55);\n"
""));
        centralwidget = new QWidget(Proyecto_ED);
        centralwidget->setObjectName("centralwidget");
        FramePrincipal = new QFrame(centralwidget);
        FramePrincipal->setObjectName("FramePrincipal");
        FramePrincipal->setGeometry(QRect(0, 30, 791, 591));
        QPalette palette;
        QBrush brush(QColor(255, 195, 55, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        FramePrincipal->setPalette(palette);
        FramePrincipal->setLayoutDirection(Qt::RightToLeft);
        FramePrincipal->setAutoFillBackground(false);
        FramePrincipal->setStyleSheet(QString::fromUtf8(""));
        FramePrincipal->setFrameShape(QFrame::StyledPanel);
        FramePrincipal->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(FramePrincipal);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 110, 151, 31));
        QPalette palette1;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(121, 121, 121, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_2->setPalette(palette1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);\n"
"color: rgb(0, 0, 0);"));
        pushButton_3 = new QPushButton(FramePrincipal);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(640, 260, 131, 31));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        LabelImagen12 = new QLabel(FramePrincipal);
        LabelImagen12->setObjectName("LabelImagen12");
        LabelImagen12->setGeometry(QRect(50, 60, 91, 91));
        LabelImagen12->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG2.jpg")));
        LabelImagen12->setScaledContents(true);
        LabelImagen2 = new QLabel(FramePrincipal);
        LabelImagen2->setObjectName("LabelImagen2");
        LabelImagen2->setGeometry(QRect(50, 180, 91, 91));
        LabelImagen2->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG4.jpg")));
        LabelImagen2->setScaledContents(true);
        LabelImagen4 = new QLabel(FramePrincipal);
        LabelImagen4->setObjectName("LabelImagen4");
        LabelImagen4->setGeometry(QRect(50, 310, 91, 91));
        LabelImagen4->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG3.jpg")));
        LabelImagen4->setScaledContents(true);
        LabelImagen3 = new QLabel(FramePrincipal);
        LabelImagen3->setObjectName("LabelImagen3");
        LabelImagen3->setGeometry(QRect(50, 430, 91, 91));
        LabelImagen3->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG1.JPG")));
        LabelImagen3->setScaledContents(true);
        pushButton_4 = new QPushButton(FramePrincipal);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(470, 150, 151, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush4(QColor(0, 0, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_4->setPalette(palette2);
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_5 = new QPushButton(FramePrincipal);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(210, 140, 201, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush5(QColor(255, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_5->setPalette(palette3);
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        pushButton_6 = new QPushButton(FramePrincipal);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(470, 190, 151, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush6(QColor(0, 170, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_6->setPalette(palette4);
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(0, 0, 0);"));
        LabelImagen6 = new QLabel(FramePrincipal);
        LabelImagen6->setObjectName("LabelImagen6");
        LabelImagen6->setGeometry(QRect(700, 100, 81, 61));
        LabelImagen6->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG6.png")));
        LabelImagen6->setScaledContents(true);
        LabelImagen8 = new QLabel(FramePrincipal);
        LabelImagen8->setObjectName("LabelImagen8");
        LabelImagen8->setGeometry(QRect(440, 250, 61, 61));
        LabelImagen8->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG7.png")));
        LabelImagen8->setScaledContents(true);
        LabelImagen7 = new QLabel(FramePrincipal);
        LabelImagen7->setObjectName("LabelImagen7");
        LabelImagen7->setGeometry(QRect(160, 260, 71, 51));
        LabelImagen7->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG8.png")));
        LabelImagen7->setScaledContents(true);
        LabelImagen10 = new QLabel(FramePrincipal);
        LabelImagen10->setObjectName("LabelImagen10");
        LabelImagen10->setGeometry(QRect(300, 0, 241, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Black")});
        font1.setPointSize(36);
        font1.setBold(true);
        LabelImagen10->setFont(font1);
        LabelImagen10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        LabelImagen9 = new QLabel(FramePrincipal);
        LabelImagen9->setObjectName("LabelImagen9");
        LabelImagen9->setGeometry(QRect(340, 30, 171, 71));
        LabelImagen9->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG10.png")));
        LabelImagen9->setScaledContents(true);
        LabelImagen9->setWordWrap(false);
        LabelImagen5 = new QLabel(FramePrincipal);
        LabelImagen5->setObjectName("LabelImagen5");
        LabelImagen5->setGeometry(QRect(510, 420, 81, 71));
        LabelImagen5->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG11.png")));
        LabelImagen5->setScaledContents(true);
        LabelImagen11 = new QLabel(FramePrincipal);
        LabelImagen11->setObjectName("LabelImagen11");
        LabelImagen11->setGeometry(QRect(190, 440, 91, 71));
        LabelImagen11->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/Im\303\241genes QT/IMG14.png")));
        LabelImagen11->setScaledContents(true);
        LabelImagen13 = new QLabel(FramePrincipal);
        LabelImagen13->setObjectName("LabelImagen13");
        LabelImagen13->setGeometry(QRect(670, 310, 81, 71));
        LabelImagen13->setPixmap(QPixmap(QString::fromUtf8("../Im\303\241genes QT/IMG13.png")));
        LabelImagen13->setScaledContents(true);
        pushButton = new QPushButton(FramePrincipal);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 460, 171, 31));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 0);\n"
"color: rgb(0, 0, 0);"));
        pushButton_7 = new QPushButton(FramePrincipal);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(460, 390, 171, 31));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_8 = new QPushButton(FramePrincipal);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(260, 270, 141, 31));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 85, 255);\n"
"color: rgb(0, 0, 0);"));
        line = new QFrame(FramePrincipal);
        line->setObjectName("line");
        line->setGeometry(QRect(140, 80, 31, 41));
        line->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(4);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(FramePrincipal);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(460, 450, 61, 41));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(4);
        line_2->setFrameShape(QFrame::HLine);
        line_3 = new QFrame(FramePrincipal);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(235, 260, 21, 41));
        line_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(4);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(FramePrincipal);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(140, 340, 31, 41));
        line_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(4);
        line_4->setFrameShape(QFrame::HLine);
        line_5 = new QFrame(FramePrincipal);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(140, 460, 31, 41));
        line_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(4);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(FramePrincipal);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(170, 310, 20, 161));
        line_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(4);
        line_6->setFrameShape(QFrame::VLine);
        line_8 = new QFrame(FramePrincipal);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(170, 110, 20, 151));
        line_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setLineWidth(4);
        line_8->setFrameShape(QFrame::VLine);
        line_7 = new QFrame(FramePrincipal);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(410, 260, 21, 41));
        line_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setLineWidth(4);
        line_7->setFrameShape(QFrame::HLine);
        line_9 = new QFrame(FramePrincipal);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(440, 100, 20, 161));
        line_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setLineWidth(4);
        line_9->setFrameShape(QFrame::VLine);
        line_19 = new QFrame(FramePrincipal);
        line_19->setObjectName("line_19");
        line_19->setGeometry(QRect(420, 140, 21, 41));
        line_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_19->setFrameShadow(QFrame::Plain);
        line_19->setLineWidth(4);
        line_19->setFrameShape(QFrame::HLine);
        line_20 = new QFrame(FramePrincipal);
        line_20->setObjectName("line_20");
        line_20->setGeometry(QRect(630, 100, 31, 41));
        line_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_20->setFrameShadow(QFrame::Plain);
        line_20->setLineWidth(4);
        line_20->setFrameShape(QFrame::HLine);
        line_21 = new QFrame(FramePrincipal);
        line_21->setObjectName("line_21");
        line_21->setGeometry(QRect(630, 140, 31, 41));
        line_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_21->setFrameShadow(QFrame::Plain);
        line_21->setLineWidth(4);
        line_21->setFrameShape(QFrame::HLine);
        line_22 = new QFrame(FramePrincipal);
        line_22->setObjectName("line_22");
        line_22->setGeometry(QRect(630, 170, 31, 41));
        line_22->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_22->setFrameShadow(QFrame::Plain);
        line_22->setLineWidth(4);
        line_22->setFrameShape(QFrame::HLine);
        line_23 = new QFrame(FramePrincipal);
        line_23->setObjectName("line_23");
        line_23->setGeometry(QRect(720, 160, 20, 91));
        line_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_23->setFrameShadow(QFrame::Plain);
        line_23->setLineWidth(4);
        line_23->setFrameShape(QFrame::VLine);
        line_24 = new QFrame(FramePrincipal);
        line_24->setObjectName("line_24");
        line_24->setGeometry(QRect(510, 260, 121, 41));
        line_24->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_24->setFrameShadow(QFrame::Plain);
        line_24->setLineWidth(4);
        line_24->setFrameShape(QFrame::HLine);
        line_25 = new QFrame(FramePrincipal);
        line_25->setObjectName("line_25");
        line_25->setGeometry(QRect(640, 390, 51, 41));
        line_25->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_25->setFrameShadow(QFrame::Plain);
        line_25->setLineWidth(4);
        line_25->setFrameShape(QFrame::HLine);
        line_26 = new QFrame(FramePrincipal);
        line_26->setObjectName("line_26");
        line_26->setGeometry(QRect(690, 380, 20, 31));
        line_26->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_26->setFrameShadow(QFrame::Plain);
        line_26->setLineWidth(4);
        line_26->setFrameShape(QFrame::VLine);
        line_27 = new QFrame(FramePrincipal);
        line_27->setObjectName("line_27");
        line_27->setGeometry(QRect(660, 100, 20, 91));
        line_27->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_27->setFrameShadow(QFrame::Plain);
        line_27->setLineWidth(4);
        line_27->setMidLineWidth(0);
        line_27->setFrameShape(QFrame::VLine);
        line_28 = new QFrame(FramePrincipal);
        line_28->setObjectName("line_28");
        line_28->setGeometry(QRect(320, 80, 341, 31));
        line_28->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_28->setFrameShadow(QFrame::Plain);
        line_28->setLineWidth(4);
        line_28->setFrameShape(QFrame::HLine);
        line_29 = new QFrame(FramePrincipal);
        line_29->setObjectName("line_29");
        line_29->setGeometry(QRect(680, 130, 16, 41));
        line_29->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_29->setFrameShadow(QFrame::Plain);
        line_29->setLineWidth(4);
        line_29->setFrameShape(QFrame::HLine);
        line_30 = new QFrame(FramePrincipal);
        line_30->setObjectName("line_30");
        line_30->setGeometry(QRect(300, 100, 20, 31));
        line_30->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_30->setFrameShadow(QFrame::Plain);
        line_30->setLineWidth(4);
        line_30->setFrameShape(QFrame::VLine);
        line_31 = new QFrame(FramePrincipal);
        line_31->setObjectName("line_31");
        line_31->setGeometry(QRect(445, 110, 21, 41));
        line_31->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_31->setFrameShadow(QFrame::Plain);
        line_31->setLineWidth(4);
        line_31->setFrameShape(QFrame::HLine);
        line_32 = new QFrame(FramePrincipal);
        line_32->setObjectName("line_32");
        line_32->setGeometry(QRect(450, 140, 16, 41));
        line_32->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_32->setFrameShadow(QFrame::Plain);
        line_32->setLineWidth(4);
        line_32->setFrameShape(QFrame::HLine);
        line_33 = new QFrame(FramePrincipal);
        line_33->setObjectName("line_33");
        line_33->setGeometry(QRect(450, 190, 16, 41));
        line_33->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_33->setFrameShadow(QFrame::Plain);
        line_33->setLineWidth(4);
        line_33->setFrameShape(QFrame::HLine);
        line_33->raise();
        line_32->raise();
        line_31->raise();
        LabelImagen9->raise();
        line_28->raise();
        pushButton_3->raise();
        LabelImagen12->raise();
        LabelImagen2->raise();
        LabelImagen4->raise();
        LabelImagen3->raise();
        pushButton_4->raise();
        pushButton_6->raise();
        LabelImagen6->raise();
        LabelImagen8->raise();
        LabelImagen7->raise();
        LabelImagen10->raise();
        pushButton_5->raise();
        pushButton_2->raise();
        LabelImagen5->raise();
        LabelImagen11->raise();
        LabelImagen13->raise();
        pushButton->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        line_4->raise();
        line_6->raise();
        line_5->raise();
        line_8->raise();
        line_7->raise();
        line_9->raise();
        line_19->raise();
        line_20->raise();
        line_21->raise();
        line_22->raise();
        line_23->raise();
        line_24->raise();
        line_25->raise();
        line_26->raise();
        line_27->raise();
        line_29->raise();
        line_30->raise();
        Proyecto_ED->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Proyecto_ED);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Proyecto_ED->setMenuBar(menubar);
        statusbar = new QStatusBar(Proyecto_ED);
        statusbar->setObjectName("statusbar");
        Proyecto_ED->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(Proyecto_ED);

        QMetaObject::connectSlotsByName(Proyecto_ED);
    } // setupUi

    void retranslateUi(QMainWindow *Proyecto_ED)
    {
        Proyecto_ED->setWindowTitle(QCoreApplication::translate("Proyecto_ED", "Proyecto_ED", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Proyecto_ED", " Cola de F\303\241brica A", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Proyecto_ED", "Cola de alisto", nullptr));
        LabelImagen12->setText(QString());
        LabelImagen2->setText(QString());
        LabelImagen4->setText(QString());
        LabelImagen3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Proyecto_ED", " Cola de F\303\241brica B", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Proyecto_ED", " Cola de F\303\241brica Comod\303\255n", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Proyecto_ED", " Cola de F\303\241brica C", nullptr));
        LabelImagen6->setText(QString());
        LabelImagen8->setText(QString());
        LabelImagen7->setText(QString());
        LabelImagen10->setText(QCoreApplication::translate("Proyecto_ED", "armazon", nullptr));
        LabelImagen9->setText(QString());
        LabelImagen5->setText(QString());
        LabelImagen11->setText(QString());
        LabelImagen13->setText(QString());
        pushButton->setText(QCoreApplication::translate("Proyecto_ED", "Cola de facturaci\303\263n", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Proyecto_ED", "Cola de alistados", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Proyecto_ED", "Cola de pedidos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Proyecto_ED: public Ui_Proyecto_ED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROYECTO_ED_H
