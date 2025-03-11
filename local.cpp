#include "local.h"

local::local() {}
local::local(QString a,int b, int c, QString d,QString e ,QString f,QString g){
    Id_locale=a;
    Etage=b;
    Nbre_accés=c;
    Superficié=d;
    Etat=e;
    Description_locale=f;
    Type_locale=g;
}
bool local::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO locale (ID_LOCALE, TYPE_LOCALE, ETAT, ETAGE, DESCRIPTION_LOCALE,SUPERFICE,NBRE_ACCES,ID_LOCATAIRE) "
                  "VALUES (:ID_LOCALE, :TYPE_LOCALE, :ETAT, :ETAGE, :DESCRIPTION_LOCALE, :SUPERFICE, :NBRE_ACCES, :ID_LOCATAIRE)");
    query.bindValue(0, Id_locale);
    query.bindValue(1, Type_locale);
    query.bindValue(2, Etat);
    query.bindValue(3, Etage);
    query.bindValue(4, Description_locale);
    query.bindValue(5, Superficié);
    query.bindValue(6, Nbre_accés);
    query.bindValue(7, "200");//forcing the add because the locataire table is empty so i created a new locataire with id 200

    return query.exec();

}

QSqlQueryModel* local::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();



    model->setQuery("SELECT* FROM locale");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_LOCALE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_LOCALE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION_LOCALE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SUPERFICE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBRE_ACCES"));



    return model;
}

bool local ::supprimer(QString id)
{
    QSqlQuery query;

    query.prepare("Delete from locale where ID_LOCALE=:id");
    query.bindValue(0, id);

    return  query.exec();

}
bool local::modifier()
{
    QSqlQuery query;
    query.prepare("update locale  set TYPE_LOCALE=:TYPE_LOCALE,ETAT=:ETAT,ETAGE=:ETAGE, DESCRIPTION_LOCALE=:DESCRIPTION_LOCALE , SUPERFICE=:SUPERFICE , NBRE_ACCES=:NBRE_ACCES  where ID_LOCALE like :ID_LOCALE");
    query.bindValue(":ID_LOCALE",this->Id_locale);
    query.bindValue(":TYPE_LOCALE",this->Type_locale);
    query.bindValue(":ETAT",this->Etat);
    query.bindValue(":ETAGE",this->Etage);
    query.bindValue(":DESCRIPTION_LOCALE",this->Description_locale);
    query.bindValue(":SUPERFICE",this->Superficié);
    query.bindValue(":NBRE_ACCES",this->Nbre_accés);
    return  query.exec();


}

