#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connectdb("SYS_MAN.db");
    ui->radioButton_stu->setChecked(true);
}

Login::~Login()
{
    delete ui;
}

void Login::connectdb(QString dbname)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("DataBase Error"),db.lastError().text());
    }
}

void Login::on_radioButton_admin_clicked()
{
    acc_pw.clear();
    acc_pw.insert("root","1111");
}

void Login::on_radioButton_tech_clicked()
{
    acc_pw.clear();
    QSqlQuery query(db);
    if(query.exec("select * from teach_acc"))
    while(query.next())
    {
        acc_pw.insert(query.value(1).toString(),query.value(2).toString());
    }
    qDebug() << acc_pw;
}

void Login::on_radioButton_stu_clicked()
{
    acc_pw.clear();
    QSqlQuery query(db);
    if(query.exec("select * from stu_acc"))
    while(query.next())
    {
        acc_pw.insert(query.value(1).toString(),query.value(2).toString());
    }
    qDebug() << acc_pw;
}

void Login::on_pushButton_login_clicked()
{
    if(ui->radioButton_admin->isChecked())
    {
        NextUI = 1;
    }
    else if(ui->radioButton_tech->isChecked())
    {
        NextUI = 2;
    }
    else
    {
        NextUI = 3;
    }
    QString account = ui->lineEdit_acc->text();
    QString password = ui->lineEdit_pw->text();

    if(acc_pw.contains(account) && acc_pw.find(account).value() == password)
    {
        close();
        id = account.toInt();
    }
    else
    {
        QMessageBox::warning(this,"err","账号或密码错误！");
        ui->lineEdit_pw->clear();
    }
}

void Login::on_pushButton_quit_clicked()
{
    close();
}