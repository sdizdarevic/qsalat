/********************************************************************************
** Form generated from reading ui file 'audio.ui'
**
** Created: Wed Dec 10 09:46:34 2008
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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

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
    QPushButton *playButton;
    QPushButton *stopButton;
    QLabel *volumeLabel;
    QRadioButton *regularRadioButton;
    QRadioButton *fajrRadioButton;
    QRadioButton *duaRadioButton;
    QFrame *playerFrame;
    QFrame *volumeFrame;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *okButton;
    QLabel *label;

    void setupUi(QDialog *Audio)
    {
    if (Audio->objectName().isEmpty())
        Audio->setObjectName(QString::fromUtf8("Audio"));
    Audio->resize(484, 461);
    Audio->setMinimumSize(QSize(484, 461));
    Audio->setMaximumSize(QSize(484, 461));
    groupBox = new QGroupBox(Audio);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 30, 461, 141));
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
    groupBox_2->setGeometry(QRect(10, 180, 461, 61));
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
    groupBox_3->setGeometry(QRect(10, 250, 461, 151));
    playButton = new QPushButton(groupBox_3);
    playButton->setObjectName(QString::fromUtf8("playButton"));
    playButton->setGeometry(QRect(20, 100, 41, 28));
    stopButton = new QPushButton(groupBox_3);
    stopButton->setObjectName(QString::fromUtf8("stopButton"));
    stopButton->setGeometry(QRect(70, 100, 41, 28));
    volumeLabel = new QLabel(groupBox_3);
    volumeLabel->setObjectName(QString::fromUtf8("volumeLabel"));
    volumeLabel->setGeometry(QRect(330, 105, 31, 21));
    regularRadioButton = new QRadioButton(groupBox_3);
    regularRadioButton->setObjectName(QString::fromUtf8("regularRadioButton"));
    regularRadioButton->setGeometry(QRect(20, 30, 131, 24));
    regularRadioButton->setChecked(true);
    fajrRadioButton = new QRadioButton(groupBox_3);
    fajrRadioButton->setObjectName(QString::fromUtf8("fajrRadioButton"));
    fajrRadioButton->setGeometry(QRect(170, 30, 111, 24));
    duaRadioButton = new QRadioButton(groupBox_3);
    duaRadioButton->setObjectName(QString::fromUtf8("duaRadioButton"));
    duaRadioButton->setGeometry(QRect(300, 30, 91, 24));
    playerFrame = new QFrame(groupBox_3);
    playerFrame->setObjectName(QString::fromUtf8("playerFrame"));
    playerFrame->setGeometry(QRect(10, 50, 441, 41));
    playerFrame->setFrameShape(QFrame::NoFrame);
    playerFrame->setFrameShadow(QFrame::Raised);
    volumeFrame = new QFrame(groupBox_3);
    volumeFrame->setObjectName(QString::fromUtf8("volumeFrame"));
    volumeFrame->setGeometry(QRect(330, 100, 121, 31));
    volumeFrame->setFrameShape(QFrame::NoFrame);
    volumeFrame->setFrameShadow(QFrame::Raised);
    cancelButton = new QPushButton(Audio);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(390, 420, 80, 28));
    saveButton = new QPushButton(Audio);
    saveButton->setObjectName(QString::fromUtf8("saveButton"));
    saveButton->setGeometry(QRect(300, 420, 80, 28));
    okButton = new QPushButton(Audio);
    okButton->setObjectName(QString::fromUtf8("okButton"));
    okButton->setGeometry(QRect(210, 420, 80, 28));
    label = new QLabel(Audio);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 461, 21));
    QFont font;
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    retranslateUi(Audio);

    QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QDialog *Audio)
    {
    Audio->setWindowTitle(QApplication::translate("Audio", "Qsalat - audio", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Audio", "Audio option", 0, QApplication::UnicodeUTF8));
    prayerButton->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    fajrButton->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    prayerLabel->setText(QApplication::translate("Audio", "Regular prayer", 0, QApplication::UnicodeUTF8));
    fajrLabel->setText(QApplication::translate("Audio", "Fajr prayer", 0, QApplication::UnicodeUTF8));
    duaButton->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    duaLineEdit->setText(QString());
    duaLabel->setText(QApplication::translate("Audio", "Dua", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Audio", "Play options", 0, QApplication::UnicodeUTF8));
    salatCheckBox->setText(QApplication::translate("Audio", "Play athan audio", 0, QApplication::UnicodeUTF8));
    duaCheckBox->setText(QApplication::translate("Audio", "Play dua audio", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Audio", "Player", 0, QApplication::UnicodeUTF8));
    playButton->setText(QString());
    stopButton->setText(QString());
    volumeLabel->setText(QString());
    regularRadioButton->setText(QApplication::translate("Audio", "Play regular athan", 0, QApplication::UnicodeUTF8));
    fajrRadioButton->setText(QApplication::translate("Audio", "Play Fajr athan", 0, QApplication::UnicodeUTF8));
    duaRadioButton->setText(QApplication::translate("Audio", "Play dua", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("Audio", "Cancel", 0, QApplication::UnicodeUTF8));
    saveButton->setText(QApplication::translate("Audio", "Apply", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("Audio", "OK", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Audio", "Set audio files and audio options", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Audio);
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
