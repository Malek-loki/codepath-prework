#include "glocal.h"
#include "ui_glocal.h"
#include "local.h"
#include <QMessageBox>
Glocal::Glocal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Glocal)
{
    ui->setupUi(this);
    local l;
    ui->tableView->setModel(l.afficher());

}

Glocal::~Glocal()
{
    delete ui;
}

void Glocal::on_pushButton_7_clicked()
{
    QString Type_locale=ui->line2->text();
    QString Id_locale=ui->line1->text();
    QString Superficié=ui->line6->text();
    QString Etat=ui->line3->text();
    QString Description_locale=ui->line5->text();
    int Etage=ui->line4->text().toInt();
    int Nbre_accés=ui->line7->text().toInt();
    local l = local(Id_locale,Etage,Nbre_accés,Superficié,Etat,Description_locale,Type_locale);
    bool test = l.ajouter();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("ajout avec succes.");
        ui->tableView->setModel(l.afficher());}
    else
        msgBox.setText("echec d'ajout");
    msgBox.exec();
}


void Glocal::on_pushButton_9_clicked()
{
    QString Type_locale=ui->linem2->text();
    QString Id_locale=ui->linem1->text();
    QString Superficié=ui->linem6->text();
    QString Etat=ui->linem3->text();
    QString Description_locale=ui->linem5->text();
    int Etage=ui->linem4->text().toInt();
    int Nbre_accés=ui->linem7->text().toInt();
    local l = local(Id_locale,Etage,Nbre_accés,Superficié,Etat,Description_locale,Type_locale);
    bool test = l.modifier();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("modification avec succes.");
        ui->tableView->setModel(l.afficher());}
    else
        msgBox.setText("echec d'modify");
    msgBox.exec();
}


void Glocal::on_pushButton_11_clicked()
{
    QString Id_locale=ui->line_supp->text();
    local l;
   bool test= l.supprimer(Id_locale);
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppresion avec succes .");
        ui->tableView->setModel(l.afficher());}
    else
        msgBox.setText("echec ");
    msgBox.exec();
}

