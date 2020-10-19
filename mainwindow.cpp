#include "mainwindow.h"
#include"fenetrecodegenerer.h"
#include <QVBoxLayout>
#include<QString>
#include<QDebug>


MainFenetre::MainFenetre() : QWidget()
{

//FENETRE DE REGLAGE

    //inisialisation de la structure principal de la fenetre

    MainFenetre::setWindowIcon(QIcon("icone.png"));
    MainFenetre::setWindowTitle("Class C++ Generator by Benjy");
    fenetrePrincipal = new QWidget(this);

        fenetrePrincipal->resize(500,600);

    mainStrucLayout = new QVBoxLayout();


//definition de la classe
    m_definitionClasseGB = new QGroupBox(fenetrePrincipal);


        m_definitionClasseGB->setTitle("Définition de classe");

        nomDCLabel = new QLabel("Nom :");
        classeMereDCLabel = new QLabel("Classe mère :");

            nomLE = new QLineEdit;
            classeMereLE = new QLineEdit;

        m_grilleLayoutDefinitionClass = new QGridLayout(m_definitionClasseGB);

            m_grilleLayoutDefinitionClass->addWidget(nomDCLabel, 0,0 );
                m_grilleLayoutDefinitionClass->addWidget(nomLE, 0,1 );
            m_grilleLayoutDefinitionClass->addWidget(classeMereDCLabel, 1,0 );
                m_grilleLayoutDefinitionClass->addWidget(classeMereLE, 1,1 );

        m_definitionClasseGB->setLayout(m_grilleLayoutDefinitionClass);

//Fin - definition de la classe

//Option
    m_definitionOptionGB = new QGroupBox("Options",fenetrePrincipal);
        m_optionCBprotect = new QCheckBox("Protéger le header contre les inclusions multiples", m_definitionOptionGB);
            m_optionCBprotect->setCheckState(Qt::Checked);
        m_optionCBConstru = new QCheckBox("Générer un constructeur par défaut", m_definitionOptionGB);
        m_optionCBDestru = new QCheckBox("Générer un destructeur", m_definitionOptionGB);
    m_optionLayout = new QVBoxLayout(m_definitionOptionGB);
        m_optionLayout->addWidget(m_optionCBprotect);
        m_optionLayout->addWidget(m_optionCBConstru);
        m_optionLayout->addWidget(m_optionCBDestru);
//Fin - option

//Ajout des commentaire
    m_commentaireGB = new QGroupBox("Ajouter des commentaires");
        m_commentaireGB->setCheckable(true);

    m_commentaireLayout = new QGridLayout(m_commentaireGB);

    m_auteurLabel = new QLabel("Auteur :");
    m_dateCreaLabel = new QLabel("Date de création :");
    m_roleDeClasseLabel = new QLabel("Rôle de classe :");

    m_auteurLE = new QLineEdit;
    m_dateCreaLE = new QDateEdit;



    m_roleDeClasseTE = new QTextEdit;

        m_commentaireLayout->addWidget(m_auteurLabel,0,0);
        m_commentaireLayout->addWidget(m_auteurLE,0,1);
        m_commentaireLayout->addWidget(m_dateCreaLabel,1,0);
        m_commentaireLayout->addWidget(m_dateCreaLE,1,1);
        m_commentaireLayout->addWidget(m_roleDeClasseLabel,2,0);
        m_commentaireLayout->addWidget(m_roleDeClasseTE,2,1);

//Fin - Ajout des commentaire
//Bouton Générer et Quitter
    m_genererQuitterLayout = new QHBoxLayout();

    m_boutonGenerer = new QPushButton("Générer");
        m_boutonGenerer->setDefault(true);
        m_boutonGenerer->setAutoDefault(true);

    m_boutonQuitter = new QPushButton("Quitter");

    m_genererQuitterLayout->addWidget(m_boutonGenerer);
    m_genererQuitterLayout->addWidget(m_boutonQuitter);

    QObject::connect(m_boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

//Fin - Bouton Générer et Quitter

    connect(m_boutonGenerer, SIGNAL(clicked()),this,SLOT(lancerFenetreGenerer()));


//
    mainStrucLayout->addWidget(m_definitionClasseGB);
    mainStrucLayout->addWidget(m_definitionOptionGB);
    mainStrucLayout->addWidget(m_commentaireGB);
    mainStrucLayout->addItem(m_genererQuitterLayout);


    fenetrePrincipal->setLayout(mainStrucLayout);

    //envoie donnee saisie dans le constructeur


}
void MainFenetre::lancerFenetreGenerer()
{



    const QString nomSend = nomLE->text();
    const QString classeMereSend = classeMereLE->text();

    QString protectionHeaderTop = *new QString("");
    QString protectionHeaderDown = *new QString("");


    if(m_optionCBprotect->isChecked())
    {
        QString nomSendUP = nomSend;
        nomSendUP = nomSendUP.toUpper();
        protectionHeaderTop = QString("#ifndef HEADER_"+nomSendUP+"\n#Define HEADER_"+nomSendUP+"\n\n");
        protectionHeaderDown = QString("#endif");
    }
//générer un constructzeur par default on/off
    QString constructeurOptionOn =  *new QString("");

    if(m_optionCBConstru->isChecked())
    {

        constructeurOptionOn = QString(nomSend+"();");
    }
//option destructeur on
    QString destructeurOptionOn =  *new QString("");

    if(m_optionCBDestru->isChecked())
    {

        destructeurOptionOn = QString("\n\t\t~"+nomSend+"();");
    }


//Commentaire activé option
    QString commentaireOptionOn =  *new QString("");
    QString auteurVar = m_auteurLE->text();

    QString dateReglage = m_dateCreaLE->date().toString("ddd MMMM d yyyy");

    QString descriptionCommentaire = m_roleDeClasseTE->toPlainText();

    if(m_commentaireGB->isChecked())
    {
        commentaireOptionOn = QString("/*\nAuteur : "+auteurVar+"\nDate de création : "
                                      +dateReglage+"\n\nRôle :\n"+descriptionCommentaire+"\n*/\n\n");
    }



    //envoi final ici
    FenetreCodeGenerer::startFenetreGenerer(nomSend,classeMereSend,protectionHeaderTop,
                                            protectionHeaderDown,constructeurOptionOn,destructeurOptionOn
                                            ,commentaireOptionOn);

}



