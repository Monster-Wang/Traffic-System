/********************************************************************************
** Form generated from reading UI file 'trafficsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICSYSTEM_H
#define UI_TRAFFICSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrafficSystemClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *TrafficSystemClass)
    {
        if (TrafficSystemClass->objectName().isEmpty())
            TrafficSystemClass->setObjectName(QStringLiteral("TrafficSystemClass"));
        TrafficSystemClass->resize(1200, 900);
        TrafficSystemClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(TrafficSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TrafficSystemClass->setCentralWidget(centralWidget);

        retranslateUi(TrafficSystemClass);

        QMetaObject::connectSlotsByName(TrafficSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrafficSystemClass)
    {
        TrafficSystemClass->setWindowTitle(QApplication::translate("TrafficSystemClass", "TrafficSystem", 0));
    } // retranslateUi

};

namespace Ui {
    class TrafficSystemClass: public Ui_TrafficSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICSYSTEM_H
