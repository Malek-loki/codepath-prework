#ifndef LOCAL_H
#define LOCAL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDoubleValidator>
#include<QtDebug>
#include<QObject>
class local
{
private:
    //Id_locale Type_locale Etat Etage Description_locale Superficié Nbre_accés
    int  Etage, Nbre_accés;

    QString Type_locale ,Id_locale, Superficié,Etat, Description_locale;
public:
    local();
    local(QString,int,int,QString,QString,QString,QString);
    void setID(QString a){Id_locale=a;};
    void setType(QString a){Type_locale=a;};
    void setEtat(QString a){Etat=a;};
    void setEtage(int a){Etage=a;};
    void setDesc(QString a){Description_locale=a;};
    void setSup(QString a){Superficié=a;};
    void setNba(int a){Nbre_accés=a;};
    QString getID(){return Id_locale;};
    QString getType(){return Type_locale;};
    QString getEtat(){return Etat;};
    int getEtage(){return Etage;};
    QString getDesc(){return Description_locale;};
    QString getSup(){return Superficié;};
    int getNba(){return Nbre_accés;};
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier( );
};

#endif // LOCAL_H
