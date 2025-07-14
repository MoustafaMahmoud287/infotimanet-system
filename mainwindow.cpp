#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i{} ; i < maxTab ; i++) ui->tabWidget->tabBar()->setTabVisible(i , false) ;

    ui->tabWidget->setCurrentIndex(m_curPos) ;

    m_door = new doorLock(*ui) ;
    m_seatBelt = new seatBelt(*ui) ;
    m_slight = new signalLight(*ui) ;
    m_light = new light(*ui) ;
    m_warning = new warning(*ui) ;
    m_cabinDir = new cabinDir(*ui) ;


    ui->fuelCon->setPixmap(QPixmap(":/Image/gas-pump.png")) ;
    ui->speed->setPixmap(QPixmap(":/Image/mileage.png")) ;
    ui->distance->setPixmap(QPixmap(":/Image/distance.png")) ;

    ui->speedGauge->rootObject()->setProperty("value" , 205) ;

    ui->speedGauge->setClearColor(Qt::transparent);
    ui->speedGauge->setAttribute(Qt::WA_TranslucentBackground);

    ui->rpmGauge->setClearColor(Qt::transparent) ;
    ui->rpmGauge->setAttribute(Qt::WA_TranslucentBackground);

    ui->fuelGuage->setClearColor(Qt::transparent) ;
    ui->fuelGuage->setAttribute(Qt::WA_TranslucentBackground);

    m_door->unlock() ;
    //m_seatBelt->unfastenSeatBelt() ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_moveRightBtn_clicked()
{
    m_curPos = (m_curPos + 1) % maxTab ;
    ui->tabWidget->setCurrentIndex(m_curPos) ;
}


void MainWindow::on_moveRightBtn1_clicked()
{
    this->on_moveRightBtn_clicked() ;
}


void MainWindow::on_moveLeftBtn1_clicked()
{
    this->on_moveLeftBtn_clicked() ;
}


void MainWindow::on_moveLeftBtn_clicked()
{
    if(m_curPos == 0) m_curPos = maxTab - 1 ;
    else m_curPos -= 1 ;
    ui->tabWidget->setCurrentIndex(m_curPos) ;
}

void MainWindow::on_signalLeftBtn_clicked()
{
    m_slight->leftLightToggle() ;
    m_slight->rightLightOff() ;
}


void MainWindow::on_hazardBtn_clicked()
{
    m_slight->hazardToggle() ;
}

void MainWindow::on_lightBtn_clicked()
{
    m_light->toggleLight() ;
}


void MainWindow::on_warningBtn_clicked()
{
    m_warning->toggleWarning() ;
}


void MainWindow::on_signalRightBtn_clicked()
{
    m_slight->rightLightToggle() ;
    m_slight->leftLightOff() ;
}

void MainWindow::on_airflowSlider_valueChanged(int value)
{
    ui->fanLcd->display(value) ;
}


void MainWindow::on_cabinSlider_valueChanged(int value)
{
    ui->cabinLcd->display(value) ;
}


void MainWindow::on_pushButton_clicked()
{
    on_moveLeftBtn_clicked() ;
}


void MainWindow::on_pushButton_2_clicked()
{
    on_moveRightBtn_clicked() ;
}

/*****************************************************/
doorLock::doorLock(Ui::MainWindow& parent) :
    m_ui {parent} {
    m_ui.carDoor->setPixmap(QPixmap(":/Image/car-door.png"));
}

void doorLock::lock(){
    m_ui.carDoor->setPixmap(QPixmap(":/Image/car-door.png")) ;
}

void doorLock::unlock(){
    m_ui.carDoor->setPixmap(QPixmap(":/Image/car-door (1).png")) ;
}


/*******************************************************/

seatBelt::seatBelt(Ui::MainWindow& parent) :
    m_ui {parent} {
    m_ui.carSeatBelt->setPixmap(QPixmap(":/Image/seat-belt.png")) ;
}

void seatBelt::fastenSeatBelt(){
    m_ui.carSeatBelt->setPixmap(QPixmap(":/Image/seat-belt.png")) ;
}

void seatBelt::unfastenSeatBelt(){
    m_ui.carSeatBelt->setPixmap(QPixmap(":/Image/seat-belt (1).png")) ;
}


/***********************************************************/
signalLight::signalLight(Ui::MainWindow& parent) :
    m_ui {parent} {
    m_ui.signalLeftBtn->setIcon(QIcon(QPixmap(":/Image/left-arrow.png"))) ;
    m_ui.hazardBtn->setIcon(QIcon(QPixmap(":/Image/hazard (2).png"))) ;
    m_ui.signalRightBtn->setIcon(QIcon(QPixmap(":/Image/right-arrow (2).png"))) ;
}

void signalLight::leftLightOn(){
    m_ui.signalLeftBtn->setIcon(QIcon(":/Image/left-arrow (1).png")) ;
}

void signalLight::rightLightOn(){
    m_ui.signalRightBtn->setIcon(QIcon(":/Image/right-arrow (3).png")) ;
}

void signalLight::leftLightOff(){
    m_ui.signalLeftBtn->setIcon(QIcon(":/Image/left-arrow.png")) ;
}

void signalLight::rightLightOff(){
    m_ui.signalRightBtn->setIcon(QIcon(":/Image/right-arrow (2).png")) ;
}

void signalLight::leftLightToggle(){
    if(m_leftSignal){
        m_leftSignal = false ;
        leftLightOff() ;
    }
    else{
        m_leftSignal = true ;
        leftLightOn() ;
    }
}

void signalLight::rightLightToggle(){
    if(m_rightSignal){
        m_rightSignal = false ;
        rightLightOff() ;
    }
    else{
        m_rightSignal = true ;
        rightLightOn() ;
    }
}

void signalLight::hazardToggle(){
    if(m_flagHazard){
        rightLightOff() ;
        leftLightOff() ;
        m_ui.hazardBtn->setIcon(QIcon(":/Image/hazard (2).png")) ;
        m_flagHazard = false ;
    }
    else{
        rightLightOn() ;
        leftLightOn() ;
        m_ui.hazardBtn->setIcon(QIcon(":/Image/hazard .png")) ;
        m_flagHazard = true ;
    }
}

/****************************************************************/
light::light(Ui::MainWindow& parent) :
    m_ui {parent} , m_isLight {false} {
    m_ui.lightBtn->setIcon(QIcon(":/Image/headlight.png")) ;
}

void light::toggleLight(){
    if(m_isLight){
        m_ui.lightBtn->setIcon(QIcon(":/Image/headlight.png")) ;
        m_isLight = false ;
    }
    else{
        m_isLight = true ;
        m_ui.lightBtn->setIcon(QIcon(":/Image/headlight (2).png")) ;
    }
}


/********************************************/

warning::warning(Ui::MainWindow& parent):
    m_ui {parent} {
    m_ui.warningBtn->setIcon(QIcon(":/Image/warning.png")) ;
}

void warning::toggleWarning(){
    if(m_isOn){
        m_isOn = false ;
        m_ui.warningBtn->setIcon(QIcon(":/Image/warning.png")) ;
    }
    else{
        m_isOn = true ;
        m_ui.warningBtn->setIcon(QIcon(":/Image/warning (1).png")) ;
    }
}

/***********************************************/

cabinDir::cabinDir(Ui::MainWindow& parent) : m_ui {parent} {
    m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
    m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
    m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
}

void cabinDir::toggleFaceAir(){
    if(m_faceFlag){
        m_faceFeetFlag = false ;
        m_faceFlag = false ;
        m_feetFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
    else{
        m_faceFlag = true ;
        m_faceFeetFlag = false ;
        m_feetFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing (1).png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
}

void cabinDir::toggleFeetAir(){
    if(m_feetFlag){
        m_faceFeetFlag = false ;
        m_faceFlag = false ;
        m_feetFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
    else{
        m_feetFlag = true ;
        m_faceFeetFlag = false ;
        m_faceFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air (2).png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
}

void cabinDir::toggleFaceFeetAir(){
    if(m_faceFeetFlag){
        m_faceFeetFlag = false ;
        m_faceFlag = false ;
        m_feetFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
    else{
        m_faceFeetFlag = true ;
        m_faceFlag = false ;
        m_feetFlag = false ;
        m_ui.faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
        m_ui.feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
        m_ui.faceFeetBtn->setIcon(QIcon(":/Image/air-flow (1).png")) ;
    }
}


void MainWindow::on_faceBtn_clicked()
{
    m_cabinDir->toggleFaceAir() ;
}


void MainWindow::on_feetBtn_clicked()
{
    m_cabinDir->toggleFeetAir() ;
}



void MainWindow::on_faceFeetBtn_clicked()
{
    m_cabinDir->toggleFaceFeetAir() ;
}

