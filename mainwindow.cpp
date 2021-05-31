#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startPB_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_goPB_clicked()
{
    ui->goPB->setEnabled(false);
    realizarPC();
}

void MainWindow::realizarPC()
{
    srand (time(NULL));
    int turn;
    int limit;
    int img;
    int contProduct=0;
    int p=0;
    int c=0;

    QPixmap producer(":/Imagenes/productor.png");
    QPixmap consumer(":/Imagenes/consumidor4.png");
    QPixmap sleep(":/Imagenes/sleep.png");
    QPixmap cancel(":/Imagenes/cancel.png");

    while(true)
    {
        turn=rand()%10+1;
        ui->consumerLB->setPixmap(sleep);

        //entra productor
        if(turn%2==0)
        {
            ui->consumerLB->setPixmap(sleep);
            ui->producerLB->setPixmap(producer);
            ui->stateConsumerLB->setText("ESTADO: durmiendo");

            limit=rand()%3+3;

            for (int i(0); i<limit; ++i) {

                if(contProduct<20)
                {
                    ui->stateProducerLB->setText("ESTADO: produciendo "+QString::number(limit-i));

                    productsArray[p]=1;
                    img=rand()%5+1;
                    putProduct(p+1,img);
                    ++contProduct;
                    ++p;
                    if(p==20)
                        p=0;
                }
                else
                {
                    ui->stateProducerLB->setText("ESTADO: intentando "+QString::number(limit-i));
                    ui->cancel1LB->setPixmap(cancel);
                }
                delay(1000);
                ui->cancel1LB->clear();
            }
        }

        //entra consumidor
        else
        {
            ui->producerLB->setPixmap(sleep);
            ui->consumerLB->setPixmap(consumer);
            ui->stateProducerLB->setText("ESTADO: durmiendo");

            limit=rand()%3+3;

            for (int i(0); i<limit; ++i) {

                if(contProduct>0)
                {
                    ui->stateConsumerLB->setText("ESTADO: consumiendo "+QString::number(limit-i));

                    productsArray[c]=1;
                    removeProduct(c+1);
                    --contProduct;
                    ++c;
                    if(c==20)
                        c=0;

                }
                else
                {
                    ui->stateConsumerLB->setText("ESTADO: intentando "+QString::number(limit-i));
                    ui->cancel2LB->setPixmap(cancel);
                }
                delay(1000);
                ui->cancel2LB->clear();
            }
        }

        if(end)
            break;
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::delay(const int &mSeconds)
{
    QTime dieTime=QTime::currentTime().addMSecs(mSeconds);
    while(QTime::currentTime()<dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::putProduct(const int &pos, const int &img)
{
    QPixmap imgPM(":/Imagenes/"+QString::number(img)+".png");

    switch (pos){
        case 1:
            ui->p1->setPixmap(imgPM);
        break;

        case 2:
            ui->p2->setPixmap(imgPM);
        break;

        case 3:
            ui->p3->setPixmap(imgPM);
        break;

        case 4:
            ui->p4->setPixmap(imgPM);
        break;

        case 5:
            ui->p5->setPixmap(imgPM);
        break;

        case 6:
            ui->p6->setPixmap(imgPM);
        break;

        case 7:
            ui->p7->setPixmap(imgPM);
        break;

        case 8:
            ui->p8->setPixmap(imgPM);
        break;

        case 9:
            ui->p9->setPixmap(imgPM);
        break;

        case 10:
            ui->p10->setPixmap(imgPM);
        break;

        case 11:
            ui->p11->setPixmap(imgPM);
        break;

        case 12:
            ui->p12->setPixmap(imgPM);
        break;

        case 13:
            ui->p13->setPixmap(imgPM);
        break;

        case 14:
            ui->p14->setPixmap(imgPM);
        break;

        case 15:
            ui->p15->setPixmap(imgPM);
        break;

        case 16:
            ui->p16->setPixmap(imgPM);
        break;

        case 17:
            ui->p17->setPixmap(imgPM);
        break;

        case 18:
            ui->p18->setPixmap(imgPM);
        break;

        case 19:
            ui->p19->setPixmap(imgPM);
        break;

        case 20:
            ui->p20->setPixmap(imgPM);
        break;

    }
}

void MainWindow::removeProduct(const int &pos)
{
    switch (pos){
        case 1:
            ui->p1->clear();
        break;

        case 2:
            ui->p2->clear();
        break;

        case 3:
            ui->p3->clear();
        break;

        case 4:
            ui->p4->clear();
        break;

        case 5:
            ui->p5->clear();
        break;

        case 6:
            ui->p6->clear();
        break;

        case 7:
            ui->p7->clear();
        break;

        case 8:
            ui->p8->clear();
        break;

        case 9:
            ui->p9->clear();
        break;

        case 10:
            ui->p10->clear();
        break;

        case 11:
            ui->p11->clear();
        break;

        case 12:
            ui->p12->clear();
        break;

        case 13:
            ui->p13->clear();
        break;

        case 14:
            ui->p14->clear();
        break;

        case 15:
            ui->p15->clear();
        break;

        case 16:
            ui->p16->clear();
        break;

        case 17:
            ui->p17->clear();
        break;

        case 18:
            ui->p18->clear();
        break;

        case 19:
            ui->p19->clear();
        break;

        case 20:
            ui->p20->clear();
        break;

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!ui->goPB->isEnabled())
        if(event->key()==Qt::Key_Escape)
            end=true;
}
