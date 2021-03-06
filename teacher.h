#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QVariant>
#include <QSqlRecord>
#include <QInputDialog>
#include <QAction>
#include <QStandardItemModel>
#include <QCompleter>
#include <QHeaderView>

namespace Ui {
class Teacher;
}

class Teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = nullptr, QString id = NULL);
    ~Teacher();
    QString id;
    bool back = false;
    int courseid;
    void connectdb(QString dbname);

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_info_clicked();

    void showStuScore();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_sea_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void setHeadData();

    void setSortWay();

private:
    Ui::Teacher *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQuery * query;
    QSqlRecord teach_record;
    QStandardItemModel *mod;
    QStringList linelist;
};

#endif // TEACHER_H
