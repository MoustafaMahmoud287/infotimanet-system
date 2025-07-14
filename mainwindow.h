#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "includeFils.h"

#define maxTab      3

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class doorLock ;
class seatBelt ;


class signalLight{
private:
    Ui::MainWindow& m_ui ;
    bool m_flagHazard {false} ;
    bool m_rightSignal {false} ;
    bool m_leftSignal  {false} ;
public:
    signalLight(Ui::MainWindow& parent) ;
    ~signalLight() = default ;
    void leftLightOn() ;
    void rightLightOn() ;
    void leftLightOff() ;
    void rightLightOff() ;
    void leftLightToggle() ;
    void rightLightToggle() ;
    void hazardToggle() ;
};


class cabinDir{
private:
    Ui::MainWindow& m_ui ;
    bool m_faceFlag {false} ;
    bool m_feetFlag {false} ;
    bool m_faceFeetFlag {false} ;

public:
    cabinDir(Ui::MainWindow& parent) ;
    ~cabinDir() = default ;
    void toggleFaceAir() ;
    void toggleFeetAir() ;
    void toggleFaceFeetAir() ;
};

class light{
private:
    Ui::MainWindow& m_ui ;
    bool m_isLight {false} ;
public:
    light(Ui::MainWindow& parent) ;
    ~light() = default ;
    void toggleLight() ;
};


class warning{
private:
    Ui::MainWindow& m_ui ;
    bool m_isOn {false} ;
public:
    warning(Ui::MainWindow& parent) ;
    ~warning() = default ;
    void toggleWarning();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_moveRightBtn_clicked();

    void on_moveRightBtn1_clicked();

    void on_moveLeftBtn1_clicked();

    void on_moveLeftBtn_clicked();

    void on_signalLeftBtn_clicked();

    void on_hazardBtn_clicked();

    void on_lightBtn_clicked();

    void on_warningBtn_clicked();

    void on_signalRightBtn_clicked();

    void on_airflowSlider_valueChanged(int value);

    void on_cabinSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_faceBtn_clicked();

    void on_feetBtn_clicked();

    void on_faceFeetBtn_clicked();

private:
    Ui::MainWindow *ui;
    doorLock* m_door;
    seatBelt* m_seatBelt ;
    signalLight* m_slight ;
    light* m_light ;
    warning* m_warning ;
    cabinDir* m_cabinDir ;

    int m_curPos{} ;
};

class doorLock {
private:
    Ui::MainWindow& m_ui ;

public:

    doorLock(Ui::MainWindow& parent) ;
    ~doorLock() = default ;
    void lock () ;
    void unlock () ;

};

class seatBelt{
private:
    Ui::MainWindow& m_ui ;
public:

    seatBelt(Ui::MainWindow& parent) ;
    ~seatBelt() = default ;
    void fastenSeatBelt() ;
    void unfastenSeatBelt() ;


};

#endif // MAINWINDOW_H





/*
    QQuickWidget *speedGauge = new QQuickWidget(this);
    speedGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    speedGauge->setSource(QUrl("qrc:/SpeedGauge.qml"));
    speedGauge->setGeometry(350 , 250 , 500 , 380) ;
    speedGauge->rootObject()->setProperty("value", 205);

    QQuickWidget *rpmGauge = new QQuickWidget(this) ;
    rpmGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    rpmGauge->setSource(QUrl("qrc:/RpmGauge.qml"));
    rpmGauge->setGeometry(615 , 620 , 220 , 170) ;
    rpmGauge->rootObject()->setProperty("value" , 4) ;


    QQuickWidget *fuelGauge = new QQuickWidget(this) ;
    fuelGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    fuelGauge->setSource(QUrl("qrc:/FuelGauge.qml"));
    fuelGauge->setGeometry(375 , 620 , 220 , 170) ;
    fuelGauge->rootObject()->setProperty("value" , 7) ;
*/

