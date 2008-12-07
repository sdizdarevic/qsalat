/********************************************************************************
** Form generated from reading ui file 'audio.ui'
**
** Created: Fri Dec 5 16:24:46 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_AUDIO_H
#define UI_AUDIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Audio
{
public:
    QGroupBox *groupBox;
    QPushButton *prayerButton;
    QPushButton *fajrButton;
    QLineEdit *prayerLineEdit;
    QLineEdit *fajrLineEdit;
    QLabel *prayerLabel;
    QLabel *fajrLabel;
    QPushButton *duaButton;
    QLineEdit *duaLineEdit;
    QLabel *duaLabel;
    QGroupBox *groupBox_2;
    QCheckBox *salatCheckBox;
    QCheckBox *duaCheckBox;
    QGroupBox *groupBox_3;
    QSlider *playSlider;
    QPushButton *playButton;
    QPushButton *stopButton;
    QSlider *volumeSlider;
    QLabel *volumeLabel;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *Audio)
    {
    if (Audio->objectName().isEmpty())
        Audio->setObjectName(QString::fromUtf8("Audio"));
    Audio->resize(484, 392);
    Audio->setMinimumSize(QSize(484, 392));
    Audio->setMaximumSize(QSize(484, 392));
    groupBox = new QGroupBox(Audio);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 461, 141));
    prayerButton = new QPushButton(groupBox);
    prayerButton->setObjectName(QString::fromUtf8("prayerButton"));
    prayerButton->setGeometry(QRect(360, 20, 91, 28));
    fajrButton = new QPushButton(groupBox);
    fajrButton->setObjectName(QString::fromUtf8("fajrButton"));
    fajrButton->setGeometry(QRect(360, 60, 91, 28));
    prayerLineEdit = new QLineEdit(groupBox);
    prayerLineEdit->setObjectName(QString::fromUtf8("prayerLineEdit"));
    prayerLineEdit->setGeometry(QRect(120, 20, 231, 28));
    fajrLineEdit = new QLineEdit(groupBox);
    fajrLineEdit->setObjectName(QString::fromUtf8("fajrLineEdit"));
    fajrLineEdit->setGeometry(QRect(120, 60, 231, 28));
    prayerLabel = new QLabel(groupBox);
    prayerLabel->setObjectName(QString::fromUtf8("prayerLabel"));
    prayerLabel->setGeometry(QRect(10, 17, 101, 31));
    fajrLabel = new QLabel(groupBox);
    fajrLabel->setObjectName(QString::fromUtf8("fajrLabel"));
    fajrLabel->setGeometry(QRect(10, 60, 101, 31));
    duaButton = new QPushButton(groupBox);
    duaButton->setObjectName(QString::fromUtf8("duaButton"));
    duaButton->setGeometry(QRect(360, 100, 91, 28));
    duaLineEdit = new QLineEdit(groupBox);
    duaLineEdit->setObjectName(QString::fromUtf8("duaLineEdit"));
    duaLineEdit->setGeometry(QRect(120, 100, 231, 28));
    duaLabel = new QLabel(groupBox);
    duaLabel->setObjectName(QString::fromUtf8("duaLabel"));
    duaLabel->setGeometry(QRect(10, 97, 101, 31));
    groupBox_2 = new QGroupBox(Audio);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 160, 461, 61));
    salatCheckBox = new QCheckBox(groupBox_2);
    salatCheckBox->setObjectName(QString::fromUtf8("salatCheckBox"));
    salatCheckBox->setGeometry(QRect(20, 30, 191, 24));
    salatCheckBox->setChecked(true);
    duaCheckBox = new QCheckBox(groupBox_2);
    duaCheckBox->setObjectName(QString::fromUtf8("duaCheckBox"));
    duaCheckBox->setGeometry(QRect(280, 30, 171, 24));
    duaCheckBox->setChecked(true);
    groupBox_3 = new QGroupBox(Audio);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 230, 461, 111));
    playSlider = new QSlider(groupBox_3);
    playSlider->setObjectName(QString::fromUtf8("playSlider"));
    playSlider->setGeometry(QRect(20, 30, 421, 20));
    playSlider->setOrientation(Qt::Horizontal);
    playButton = new QPushButton(groupBox_3);
    playButton->setObjectName(QString::fromUtf8("playButton"));
    playButton->setGeometry(QRect(20, 60, 41, 28));
    stopButton = new QPushButton(groupBox_3);
    stopButton->setObjectName(QString::fromUtf8("stopButton"));
    stopButton->setGeometry(QRect(70, 60, 41, 28));
    volumeSlider = new QSlider(groupBox_3);
    volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
    volumeSlider->setGeometry(QRect(320, 70, 121, 16));
    volumeSlider->setValue(99);
    volumeSlider->setOrientation(Qt::Horizontal);
    volumeLabel = new QLabel(groupBox_3);
    volumeLabel->setObjectName(QString::fromUtf8("volumeLabel"));
    volumeLabel->setGeometry(QRect(290, 69, 31, 16));
    cancelButton = new QPushButton(Audio);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(390, 350, 80, 28));
    saveButton = new QPushButton(Audio);
    saveButton->setObjectName(QString::fromUtf8("saveButton"));
    saveButton->setGeometry(QRect(290, 350, 80, 28));

    retranslateUi(Audio);

    QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QDialog *Audio)
    {
    Audio->setWindowTitle(QApplication::translate("Audio", "Qsalat - audio", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Audio", "Audio option", 0, QApplication::UnicodeUTF8));
    prayerButton->setText(QString());
    fajrButton->setText(QString());
    prayerLabel->setText(QApplication::translate("Audio", "Regular prayer", 0, QApplication::UnicodeUTF8));
    fajrLabel->setText(QApplication::translate("Audio", "Fajr prayer", 0, QApplication::UnicodeUTF8));
    duaButton->setText(QString());
    duaLineEdit->setText(QString());
    duaLabel->setText(QApplication::translate("Audio", "Dua", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Audio", "Play options", 0, QApplication::UnicodeUTF8));
    salatCheckBox->setText(QApplication::translate("Audio", "Play athan audio", 0, QApplication::UnicodeUTF8));
    duaCheckBox->setText(QApplication::translate("Audio", "Play dua audio", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Audio", "Player", 0, QApplication::UnicodeUTF8));
    playButton->setText(QString());
    stopButton->setText(QString());
    volumeLabel->setText(QString());
    cancelButton->setText(QApplication::translate("Audio", "Cancel", 0, QApplication::UnicodeUTF8));
    saveButton->setText(QApplication::translate("Audio", "Save", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Audio);
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
